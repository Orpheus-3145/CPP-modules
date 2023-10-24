/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 00:43:46 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 00:44:22 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
