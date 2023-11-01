/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 22:11:43 by fra           #+#    #+#                 */
/*   Updated: 2023/11/01 21:30:04 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	std::string			input = "";
	std::vector<int>	vectInput;
	std::list<int>		listInput;
	PmergeMe 			merger;

	if (argc == 2)
		input = argv[1];
	else
	{
		for (int i = 1; i < argc; i++)
			input += std::string(argv[i]).append(" ");
	}
	try
	{
		merger = input;
		vectInput = merger._toVector();
		listInput = merger._toList();
	}
	catch(MergeException const& e)
	{
		std::cerr <<"Error: " << e.what() << std::endl;
		return (1);
	}
	// for (auto item : vectInput)
	// 	std::cout << item << "  ";
	// std::cout << std::endl;
	merger.sort<std::vector<int> >(vectInput);
	// merger.sort<std::list<int> >(listInput);
	return(0);
}