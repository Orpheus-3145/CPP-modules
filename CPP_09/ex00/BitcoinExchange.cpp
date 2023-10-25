/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 00:43:46 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 17:30:26 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

typedef std::map<time_t, float> data_t;

BitcoinExchange::BitcoinExchange( std::string dbPath, std::string inputFilePath ) noexcept :
	_dbPath(dbPath) , _inputFilePath(inputFilePath) {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const& other ) noexcept :
	_database(other.getDatabase()) , _dbPath(other.getDbPath()) , _inputFilePath(other.getInputFile()) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) noexcept
{
	if (this != &other )
	{
		this->_database = other.getDatabase();
		this->_dbPath = other.getDbPath();
		this->_inputFilePath = other.getInputFile();
	}
	return (*this);
}

time_t	BitcoinExchange::getTimestamp(std::string to_cast, bool checkInput)
{
	if (checkInput)
	{
		if (to_cast.length() != 10)
			throw(BitException("invalid date format"));
		for (char check : to_cast)
		{
			if ((check != '-') and (std::isdigit(check) == 0))
				throw(BitException("invalid date"));
		}
	}
	std::tm t = {};
	std::istringstream dateStream(to_cast);
	dateStream >> std::get_time(&t, "%Y-%m-%d");
	return (std::mktime(&t));
}

float	BitcoinExchange::getValue(std::string strValue, bool checkInput)
{
	std::istringstream floatStream(strValue);
	float value;
	floatStream >> value;
	if (checkInput)
	{
		if (floatStream.fail() or !floatStream.eof())
			throw(BitException("invalid number"));
		else if ((value < 0.f) or (value > 1000.f))
			throw(BitException("number out of bounds [0 - 1000]"));
	}
	return (value);
}

data_t const	BitcoinExchange::getDatabase( void ) const noexcept 
{
	return (this->_database);
}

void	BitcoinExchange::setDatabase( data_t const& newDB ) noexcept
{
	this->_database = newDB;
}

std::string const&	BitcoinExchange::getDbPath( void ) const noexcept 
{
	return(this->_dbPath);
}

void	BitcoinExchange::setDbPath( std::string const& newDbPath) noexcept
{
	this->_dbPath = newDbPath;
}

std::string const&	BitcoinExchange::getInputFile( void ) const noexcept
{
	return(this->_inputFilePath);
}

void	BitcoinExchange::setInputFile( std::string const& newInputFile) noexcept
{
	this->_inputFilePath = newInputFile;
}

void	BitcoinExchange::fillData( void ) noexcept
{
	std::ifstream	readDB(this->_dbPath);
	std::string		line;
	std::string		dateStr;
	std::string		amountStr;
	size_t  		commaPos;

	if (!readDB.is_open())
	{
		std::cerr <<"error opening file: " << this->_dbPath << std::endl;
		return ;
	}
	std::getline(readDB, line);		// skip header line
	while (std::getline(readDB, line))
	{
		commaPos = line.find(",");
		dateStr = line.substr(0, commaPos);
		amountStr = line.substr(commaPos + 1);
		_addNewItem(getTimestamp(dateStr, false), getValue(amountStr, false));
	}
	readDB.close();
}

void	BitcoinExchange::readInput( void ) const noexcept
{
	if (this->_database.empty() == true)
	{
		std::cerr <<"app error: empty database" << std::endl;
		return ;
	}

	std::ifstream	readInput(this->_inputFilePath);
	std::string 	line;
	if (!readInput.is_open())
	{
		std::cerr <<"error opening file: " << this->_inputFilePath << std::endl;
		return ;
	}
	std::getline(readInput, line);		// skip header line
	while (std::getline(readInput, line))
	{
		try
		{
			this->_printLine(line);
		}
		catch(BitException const& e)
		{
			std::cout <<"parse error: " << e.what() << std::endl;
		}
	}
	readInput.close();
}

float	BitcoinExchange::_getAmountByDate( time_t ts ) const noexcept
{
	try
	{
		return(this->_database.at(ts));
	}
	catch(const std::out_of_range& e)
	{
		ts -= 86400;
		return (_getAmountByDate(ts));
	}
}

void	BitcoinExchange::_printLine(std::string line) const
{
	std::string		dateStr;
	time_t			timestamp;
	std::string		valueStr;
	float			value;
	float			amount;
	size_t  		pipePos;

	pipePos = line.find("|");
	if (line.find("|") == std::string::npos)
		throw(BitException("invalid line input"));
	dateStr = line.substr(0, pipePos - 1);
	valueStr = line.substr(pipePos + 2);
	try
	{
		timestamp = this->getTimestamp(dateStr, true);
		value = this->getValue(valueStr, true);
	}
	catch(BitException const& e)
	{
		throw(BitException(e));
	}
	amount = this->_getAmountByDate(timestamp);
	std::cout << dateStr << " --> " << valueStr << ": " << amount * value << std::endl;
}

void	BitcoinExchange::_addNewItem( time_t timestamp, float amount ) noexcept
{
	this->_database.insert(std::pair<time_t,float>(timestamp, amount));
}
