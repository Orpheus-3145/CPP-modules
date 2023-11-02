/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 22:11:43 by fra           #+#    #+#                 */
/*   Updated: 2023/11/02 20:48:30 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	std::string			input;
	PmergeMe 			merger;
	std::vector<int>	vectInput;
	std::list<int>		listInput;

	if (argc < 2)
	{
		std::cerr <<"No input provided" << std::endl;
		return (1);
	}
	else if (argc == 2)
		input = argv[1];
	else
	{
		for (int i = 1; i < argc; i++)
			input += std::string(argv[i]).append(" ");
	}
	try
	{
		merger.setString(input);
		vectInput = merger.toVector();
		listInput = merger.toList();
	}
	catch(MergeException const& e)
	{
		std::cerr <<"Error: " << e.what() << std::endl;
		return (1);
	}
	// merger.sort<std::vector<int> >(vectInput);
	merger.sort<std::list<int> >(listInput);
	return(0);
}