/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 20:53:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/15 20:42:33 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	std::cout << "----------Input-----------" << std::endl;
	ScalarConverter::convert(argv[1]);
	std::cout << "--------------------------\n" << std::endl;
	std::cout << "----------Tests-----------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("0.1");
	std::cout << std::endl;
	ScalarConverter::convert("1.0f");
	std::cout << std::endl;
	ScalarConverter::convert("2.f");
	std::cout << std::endl;
	ScalarConverter::convert(".2f");
	std::cout << std::endl;
	ScalarConverter::convert("'a'");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("-42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("' '");
	std::cout << "--------------------------\n" << std::endl;
	return (0);
}