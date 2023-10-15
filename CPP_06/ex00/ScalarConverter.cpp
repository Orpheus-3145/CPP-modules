/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 02:17:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 01:25:23 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	coutChar(char number, bool isOF)
{
	std::cout << "char: ";
	if (isOF == true)
		std::cout << "impossible" << std::endl;
	else if ((number < 33) or (number == 127))
		std::cout << "not displayable" << std::endl;
	else
		std::cout << "'" << number << "'" << std::endl;
}

static void coutInt(int number, bool isOF)
{
	std::cout << "int: ";
	if (isOF == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << number << std::endl;
}

static void coutFloat(float number)
{
	std::cout << "float: " << number;
	if ((number - long(number)) == 0) 
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void coutDouble(double number)
{
	std::cout << "double: " << number;
	if ((number - long(number)) == 0) 
		std::cout << ".0";
	std::cout << std::endl;
}

static void printChar( std::string const& number )
{
	char	charNum;

	charNum = number.c_str()[1];
	coutChar(charNum, false);
	coutInt((int) charNum, false);
	coutFloat((float) charNum);
	coutDouble((double) charNum);
}

static void printInt( std::string const& number )
{
	int		intNum;
	bool	isOF;

	intNum = std::atoi(number.c_str());
	isOF = (intNum < 0) or (intNum > 127);
	coutChar((char) intNum, isOF);
	coutInt(intNum, false);
	coutFloat((float) intNum);
	coutDouble((double) intNum);
}

static void printFloat( std::string const& number )
{
	float	floatNum;
	bool	isOF;

	floatNum = std::strtof(number.c_str(), NULL);
	isOF = (floatNum < 0) or (floatNum > 127) or 
			(std::isinf(floatNum) == true) or 
			(std::isnan(floatNum) == true);
	coutChar((char) floatNum, isOF);
	isOF = (floatNum < std::numeric_limits<int>::min()) or 
			(floatNum > std::numeric_limits<int>::max()) or
			(std::isinf(floatNum) == true) or
			(std::isnan(floatNum) == true);
	coutInt((int) floatNum, isOF);
	coutFloat(floatNum);
	coutDouble((double) floatNum);
}

static void printDouble( std::string const& number )
{
	double	doubleNum;
	bool	isOF;

	doubleNum = std::strtod(number.c_str(), NULL);
	isOF = (doubleNum < 0) or (doubleNum > 127) or
			(std::isinf(doubleNum) == true) or
			(std::isnan(doubleNum) == true);
	coutChar((char) doubleNum, isOF);
	isOF = (doubleNum < std::numeric_limits<int>::min()) or 
			(doubleNum > std::numeric_limits<int>::max()) or 
			(std::isinf(doubleNum) == true) or
			(std::isnan(doubleNum) == true);
	coutInt((int) doubleNum, isOF);
	coutFloat( (float) doubleNum);
	coutDouble( doubleNum );
}

static bool isChar( std::string const& number )
{
	return ((number.length() == 3) and (number[0] == '\'') and (number[2] == '\''));
}

static bool isInt( std::string const& number )
{
	size_t	start = 0;

	if (number.length() == 0)
		return (false);
	if ((number[start] == '+') or (number[start] == '-'))
	{
		if (start == number.length())
			return (false);
		else
			start++;
	}
	for (; start < number.length(); start++)
	{
		if (std::isdigit(number[start]) == 0)
			return (false);
	}
	return (start == number.length());
}

static bool isFloat( std::string const& number )
{
	size_t	start = 0;

	if ((number.compare("-inff") == 0) or (number.compare("+inff") == 0) or (number.compare("nanf") == 0))
		return (true);
	else if (number.length() == 0)
		return (false);
	if ((number[start] == '+') or (number[start] == '-'))
	{
		start++;
		if (start >= number.length())
			return (false);
	}
	for (; ; start++)
	{
		if (start >= number.length())
			return (false);
		else if (number[start] == '.')
			break ;
		else if (std::isdigit(number[start]) == 0)
			return (false);
	}
	start++;
	if (start >= number.length())
		return (false);
	for (; start < number.length(); start++)
	{
		if (number[start] == 'f')
			break ;
		else if (std::isdigit(number[start]) == 0)
			return (false);
	}
	return (start == number.length() - 1);
}

static bool isDouble( std::string const& number )
{
	size_t	start = 0;

	if ((number.compare("-inf") == 0) or (number.compare("+inf") == 0) or (number.compare("nan") == 0))
		return (true);
	else if (number.length() == 0)
		return (false);
	if ((number[start] == '+') or (number[start] == '-'))
	{
		start++;
		if (start >= number.length())
			return (false);
	}
	for (; ; start++)
	{
		if (start >= number.length())
			return (false);
		else if (number[start] == '.')
			break ;
		else if (std::isdigit(number[start]) == 0)
			return (false);
	}
	start++;
	if (start >= number.length())
		return (false);
	for (; start < number.length(); start++)
	{
		if (std::isdigit(number[start]) == 0)
			return (false);
	}
	return (start == number.length());
}

void	ScalarConverter::convert( std::string const& number )
{
	if (isChar(number) == true)
		printChar(number);
	else if (isInt(number) == true)
		printInt(number);
	else if (isFloat(number) == true)
		printFloat(number);
	else if (isDouble(number) == true)
		printDouble(number);
	else
		std::cout << "invalid input " << std::endl;
}