/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 23:37:47 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 17:06:26 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "invalid arguments, input file requested" << std::endl;
		return (0);
	}
	BitcoinExchange btcApp(DATA_PATH, argv[1]);
	btcApp.fillData();
	btcApp.readInput();
	return (0);
}