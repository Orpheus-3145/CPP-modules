/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 22:11:43 by fra           #+#    #+#                 */
/*   Updated: 2023/11/24 23:18:27 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

std::string	readFile(std::string fileName)
{
	std::ifstream readFile(fileName);
	std::string line;
	std::string number;
	std::string input;

	if (readFile.is_open() == false)
		return (input);
	while (std::getline(readFile, line))
	{
    	std::stringstream	ss(line);
		while (ss >> number)
			input.append(number + std::string(" "));
	}
	readFile.close();
	return (input);
}

std::string	storeInput(int argc, char** argv)
{
	std::string	input;

	if (argc == 2)
		input = argv[1];
	else if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
			input += std::string(argv[i]).append(" ");
	}
	return (input);
}

int main(int argc, char** argv)
{
	std::string			input;
	PmergeMe 			merger;
	std::vector<int>	vectInput;
	std::list<int>		listInput;

	input = storeInput(argc, argv);
	merger.setString(input);
	vectInput = merger.toVector();
	merger.sort<std::vector<int> >(vectInput);
	listInput = merger.toList();
	merger.sort<std::list<int> >(listInput);
	return(0);
}