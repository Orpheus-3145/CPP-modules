/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 20:53:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/15 19:26:20 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char** argv )
{
	// check args?
	if ( argc == 2 )
		ScalarConverter::convert(argv[1]);
	// (void) argc;
	// (void) argv;
	// float tmp = float(std::numeric_limits<int>::max()) + 1;
	// int tmp2 = std::numeric_limits<int>::max();
	// std::cout << "max int (2147483647) in float: " << tmp << std::endl;
	// if ( tmp > tmp2 )
	// 	std::cout << "ok!" << std::endl;
	// else if ( tmp < tmp2 )
	// 	std::cout << "non ok! " << tmp2 << " " << std::setprecision(10) << tmp << std::endl;
	// else
	// 	std::cout << "coddiooo! " << tmp2 << " " << tmp << " - " << tmp - float(tmp2) << std::endl;
	return (0);
}