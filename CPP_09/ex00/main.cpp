/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 23:37:47 by fra           #+#    #+#                 */
/*   Updated: 2023/12/04 18:14:44 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cout << "invalid arguments, input file required" << std::endl;
		return(EXIT_FAILURE);
	}
	BitcoinExchange btcApp(argv[1]);
	try
	{
		btcApp.fillData();
		btcApp.readInput();
	}
	catch (BitException const& e)
	{
		std::cerr << "btc error - " << e.what() << '\n';
		return(EXIT_FAILURE);
	}	
	return(EXIT_SUCCESS);
}