/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 02:17:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/15 20:43:00 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	printChar(char number, bool isOF)
{
	std::cout << "char: ";
	if (isOF == true)
		std::cout << "impossible" << std::endl;
	else if ((number < 33) or (number == 127))
		std::cout << "not displayable" << std::endl;
	else
		std::cout << "'" << number << "'" << std::endl;
}

static void printInt(int number, bool isOF)
{
	std::cout << "int: ";
	if (isOF == true)
		std::cout << "impossible" << std::endl;
	else
		std::cout << number << std::endl;
}

static void printFloat(float number)
{
	std::cout << "float: " << number;
	if ((number - long(number)) == 0) 
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void printDouble(double number)
{
	std::cout << "double: " << number;
	if ((number - long(number)) == 0) 
		std::cout << ".0";
	std::cout << std::endl;
}

static void	isChar( std::string number )
{
	char	charNum = number.c_str()[1];

	printChar(charNum, false);
	printInt((int) charNum, false);
	printFloat((float) charNum);
	printDouble((double) charNum);
}

static void	isInt( std::string number )
{
	int		intNum = std::atoi(number.c_str());
	bool	isOF = (intNum < 0) or (intNum > 127);

	printChar((char) intNum, isOF);
	printInt((int) intNum, false);
	printFloat((float) intNum);
	printDouble((double) intNum);
}

static void	isFloat( std::string number )
{
	float	floatNum = std::strtof(number.c_str(), NULL);
	bool	isOF = false;

	isOF = (floatNum < 0) or (floatNum > 127) or 
			(std::isinf(floatNum) == true) or 
			(std::isnan(floatNum) == true);
	printChar((char) floatNum, isOF);
	isOF = (floatNum < std::numeric_limits<int>::min()) or 
			(floatNum > std::numeric_limits<int>::max()) or
			(std::isinf(floatNum) == true) or
			(std::isnan(floatNum) == true);
	printInt((int) floatNum, isOF);
	printFloat(floatNum);
	printDouble((double) floatNum);
}

static void	isDouble( std::string number )
{
	double	doubleNum = std::strtod(number.c_str(), NULL);
	bool	isOF = false;

	isOF = (doubleNum < 0) or (doubleNum > 127) or
			(std::isinf(doubleNum) == true) or
			(std::isnan(doubleNum) == true);
	printChar((char) doubleNum, isOF);
	isOF = (doubleNum < std::numeric_limits<int>::min()) or 
			(doubleNum > std::numeric_limits<int>::max()) or 
			(std::isinf(doubleNum) == true) or
			(std::isnan(doubleNum) == true);
	printInt((int) doubleNum, isOF);
	printFloat( (float) doubleNum);
	printDouble( doubleNum );
}

void	ScalarConverter::convert( std::string const& number )
{
	if ((number.compare("-inff") == 0) or
		(number.compare("+inff") == 0) or
		(number.compare("nanf") == 0))
		isFloat(number);
	else if ((number.compare("-inf") == 0) or
			(number.compare("+inf") == 0) or
			(number.compare("nan") == 0))
		isDouble(number);
	else if (number.find(".") != std::string::npos)
	{
		if (number.find("f") != std::string::npos)
			isFloat(number);
		else
			isDouble(number);
	}
	else
	{
		if ((number.length() == 3) and (number[0] == '\'') and (number[2] == '\''))
			isChar(number);
		else
			isInt(number);
	}
}