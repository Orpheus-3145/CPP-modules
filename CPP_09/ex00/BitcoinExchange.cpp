/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 00:43:46 by fra           #+#    #+#                 */
/*   Updated: 2023/12/04 18:44:05 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

typedef std::map<time_t, float> data_t;

BitcoinExchange::BitcoinExchange( BitcoinExchange const& other ) noexcept :
	_database(other.getDatabase()) , _inputFilePath(other.getInputFile()) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) noexcept
{
	if (this != &other )
	{
		this->_database = other.getDatabase();
		this->_inputFilePath = other.getInputFile();
	}
	return (*this);
}

void	BitcoinExchange::checkTimestamp( std::string toCheck )
{
	std::string date[3];
	int count=0, start=0;
	size_t pos=std::string::npos;

	if (toCheck.length() != 10)
		throw(BitException("invalid date, format is 'YYYY-MM-DD': " + toCheck));
	while (count < 3)
	{
		pos = toCheck.find('-', start);
		if ((pos == std::string::npos) and (count < 2))
			throw(BitException("invalid date, format is 'YYYY-MM-DD': " + toCheck));
		date[count++] = toCheck.substr(start, pos);
		start = pos + 1;
	}
	try
	{
		std::stoi(std::string(date[0]));
		if ((std::stoi(std::string(date[1])) < 0) or (std::stoi(std::string(date[1])) > 12))
			throw(BitException("invalid date, bad month: " + toCheck));
		else if ((std::stoi(std::string(date[2])) < 0) or (std::stoi(std::string(date[2])) > 31))
			throw(BitException("invalid date, bad day: " + toCheck));
	}
	catch (std::invalid_argument&)
	{
		throw(BitException("invalid date, failed to convert: " + toCheck));
	}
	catch (std::out_of_range&)
	{
		throw(BitException("invalid date, out of range: " + toCheck));
	}
}

time_t	BitcoinExchange::getTimestamp(std::string to_cast)
{
	BitcoinExchange::checkTimestamp(to_cast);

	std::tm t = {};
	std::istringstream dateStream(to_cast);
	dateStream >> std::get_time(&t, "%Y-%m-%d");
	return (std::mktime(&t));
}

void	BitcoinExchange::checkValue( std::string toCheck, float& value, bool check )
{
	double bigNumber;
	std::istringstream doubleStream(toCheck);

	doubleStream >> bigNumber;
	if (check == true)
	{
		if (doubleStream.fail() or !doubleStream.eof())
			throw(BitException("invalid number: " + toCheck));
		else if ((bigNumber < 0.) or (bigNumber > 1000.))
			throw(BitException("number out of bounds [0 - 1000]: " + toCheck));
	}
	value = bigNumber;
}

float	BitcoinExchange::getValue(std::string strValue, bool check)
{
	float value = 0.0f;
	BitcoinExchange::checkValue(strValue, value, check);
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

std::string const&	BitcoinExchange::getInputFile( void ) const noexcept
{
	return(this->_inputFilePath);
}

void	BitcoinExchange::setInputFile( std::string const& newInputFile) noexcept
{
	this->_inputFilePath = newInputFile;
}

void	BitcoinExchange::fillData( void )
{
	std::ifstream	readDB(DATA_PATH);
	std::string		line;
	std::string		dateStr;
	std::string		amountStr;
	size_t  		commaPos;

	if (!readDB.is_open())
	{
		std::cerr <<"error opening file: " << DATA_PATH << std::endl;
		return ;
	}
	std::getline(readDB, line);		// skip header line
	while (std::getline(readDB, line))
	{
		commaPos = line.find(",");
		dateStr = line.substr(0, commaPos);
		amountStr = line.substr(commaPos + 1);
		try
		{
			this->_addNewItem(getTimestamp(dateStr), getValue(amountStr, false));
		}
		catch( BitException const& e)
		{
			readDB.close();
			throw(e);
		}
		
	}
	readDB.close();
}

void	BitcoinExchange::readInput( void ) const
{
	if (this->_database.empty() == true)
		throw(BitException("empty database"));
	std::ifstream	readInput(this->_inputFilePath);
	std::string 	line;

	if (!readInput.is_open())
		throw(BitException("error opening file " + this->_inputFilePath));
	std::getline(readInput, line);		// skip header line
	while (std::getline(readInput, line))
	{
		try
		{
			this->_printLine(line);
		}
		catch(BitException const& e)
		{
			std::cerr << "error: " << e.what() << '\n';
		}
	}
	readInput.close();
}

float	BitcoinExchange::_getAmountByDate( time_t ts, int max ) const
{
	try
	{
		if (max == 0)
			throw(BitException("no record found in the past year"));
		return(this->_database.at(ts));
	}
	catch(const std::out_of_range& e)
	{
		return (_getAmountByDate(ts - 86400, max - 1));
	}
}

void	BitcoinExchange::_printLine(std::string line) const
{
	std::string		dateStr;
	time_t			timestamp;
	std::string		valueStr;
	float			value;
	size_t  		pipePos;

	if (line.empty() == true)
		throw(BitException("empty line"));
	pipePos = line.find("|");
	if (line.find("|") == std::string::npos)
		throw(BitException("no separator '|' : " + line));
	dateStr = line.substr(0, pipePos - 1);
	valueStr = line.substr(pipePos + 2);
	timestamp = getTimestamp(dateStr);
	value = getValue(valueStr, true);
	std::cout << dateStr << " --> " << valueStr << ": " << value * this->_getAmountByDate(timestamp) << std::endl;
}

void	BitcoinExchange::_addNewItem( time_t timestamp, float amount ) noexcept
{
	this->_database.insert(std::pair<time_t,float>(timestamp, amount));
}
