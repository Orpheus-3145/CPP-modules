/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 18:54:20 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 19:16:08 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char** argv )
{
	if (argc < 2)
	{
		std::cout << "insuffient arguments" << std::endl;
		return (0);
	}
	RPN parser;
	for (int i = 1; i < argc; i++)
		parser.printResult(argv[i]);
	return (0);
}