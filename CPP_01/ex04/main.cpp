/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 23:44:33 by fra           #+#    #+#                 */
/*   Updated: 2023/09/29 03:59:58 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cout << "Invalid parameters" << std::endl;
		return (0);
	}
	try
	{
		Replacer obj = Replacer(argv[1], argv[2], argv[3]);
		return (obj.replace());
	}
	catch (std::invalid_argument const& err)
	{
		std::cout << "Invalid parameters" << std::endl;
		return (0);
	}
}