/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 23:37:47 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 02:12:43 by fra           ########   odam.nl         */
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
	BitcoinExchange btcApp(argv[1]);
	btcApp.fillData(DATA_PATH);
	return (0);
}