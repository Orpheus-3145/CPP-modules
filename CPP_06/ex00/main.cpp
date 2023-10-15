/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 20:53:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 01:17:58 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char** argv )
{
	std::string tmp;

	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	std::cout << "----------Input-----------" << std::endl;
	ScalarConverter::convert(argv[1]);
	std::cout << "--------------------------" << std::endl;
	std::cout << "----------Tests-----------" << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "0.0";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "0.00000f";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "2.3.4";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "4.56";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "'a'";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "a.34";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	tmp = "34.234f";
	std::cout << "test with: " << tmp << std::endl;
	ScalarConverter::convert(tmp);
	std::cout << std::endl;
	std::cout << "--------------------------\n" << std::endl;
	return (0);
}