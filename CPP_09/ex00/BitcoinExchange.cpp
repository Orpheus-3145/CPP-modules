/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 00:43:46 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 02:26:55 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

typedef std::map<time_t, float> data_t;

BitcoinExchange::BitcoinExchange( std::string inputFile ) noexcept :
	_inputFile(inputFile) {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const& other ) noexcept :
	_database(other.getDatabase()) , _inputFile(other.getInputFile()) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) noexcept
{
	if (this != &other )
	{
		this->_database = other.getDatabase();
		this->_inputFile = other.getInputFile();
	}
	return (*this);
}

time_t	BitcoinExchange::getTimestamp(std::string to_cast) noexcept
{
	std::tm t = {};
	std::istringstream dateStream(to_cast);
	dateStream >> std::get_time(&t, "%Y-%m-%d");
	return (std::mktime(&t));
}

float	BitcoinExchange::getValue(std::string strValue) noexcept
{
	std::istringstream floatStream(strValue);
	float value;
	floatStream >> value;
	return (value);
}

bool BitcoinExchange::isDate(std::string toCheck) noexcept
{
	if (toCheck.length() != 10)
		return (false);
	for (char check : toCheck)
	{
		if ((check != '-') and (std::isdigit(check) != 0))
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isValue(std::string toCheck) noexcept
{
	std::istringstream stream(toCheck);
	float tmp;
	stream >> tmp;
	return (!stream.fail() and stream.eof());
}

data_t const	BitcoinExchange::getDatabase( void ) const 
{
	return (this->_database);
}

void	BitcoinExchange::setDatabase( data_t const& newDB )
{
	this->_database = newDB;
}

std::string const&	BitcoinExchange::getInputFile( void ) const 
{
	return(this->_inputFile);
}

void				BitcoinExchange::setInputFile( std::string const& newInputFile)
{
	this->_inputFile = newInputFile;
}

void	BitcoinExchange::fillData(std::string file_path)
{
	std::ifstream	readDB(file_path);
	std::string		line;
	std::string		dateStr;
	std::string		amountStr;
	size_t  		commaPos;

	if (!readDB.is_open())
		throw(BitException(std::string("Error opening file: ") + file_path));
	std::getline(readDB, line);		// skip header line
	while (std::getline(readDB, line))
	{
		commaPos = line.find(",");
		dateStr = line.substr(0, commaPos);
		amountStr = line.substr(commaPos + 1);
		_addNewItem(dateStr, amountStr);
	}
	readDB.close();
	for (auto item : this->_database)
	{
		char buffer[11];
		std::tm* timeinfo = std::localtime(&item.first);
		std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    	std::cout << buffer  << "," << item.second << std::endl;
		// std::cout << item.first << "," << item.second << std::endl;
	}
}

float	BitcoinExchange::getValueByDate( time_t ) const
{
	return (0.0);
}

bool	BitcoinExchange::checkInputFile( std::string ) const
{
	return (true);
}

void	BitcoinExchange::_addNewItem( std::string dateStr, std::string amountStr )
{
	time_t	timestamp = getTimestamp(dateStr);
	float	amount = getValue(amountStr);
	this->_database.insert(std::pair<time_t,float>(timestamp, amount));
}
