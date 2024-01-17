/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 22:11:43 by fra           #+#    #+#                 */
/*   Updated: 2024/01/17 13:16:58 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	try {
		merger.setString(input);
	}
	catch(const MergeException& e) {
		std::cerr << "input error " << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	vectInput = merger.toVector();
	merger.sort<std::vector<int> >(vectInput);
	listInput = merger.toList();
	merger.sort<std::list<int> >(listInput);
	return(EXIT_SUCCESS);
}