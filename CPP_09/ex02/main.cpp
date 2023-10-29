/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 22:11:43 by fra           #+#    #+#                 */
/*   Updated: 2023/10/30 00:28:30 by fra           ########   odam.nl         */
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

	for (int i = 1; i < argc; i++)
		input += std::string(argv[i]).append(" ");
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
	// merger.sort<std::vector<int> >(vectInput);
	// merger.sort<std::list<int> >(listInput);

	std::vector<int> tmp;
	int ins;
	ins = 57;
	tmp = {123, 234, 56, 788, 343, 656, 87,9, 45};
	std::sort(tmp.begin(), tmp.end());
	// for (unsigned int i=0; i<tmp.size(); i++)
	// 	std::cout << i << "\t";
	// std::cout << "\n";
	for (auto item : tmp)
		std::cout << item << "\t";
	std::cout << "\n";
	merger._binaryInsert(tmp, ins, 0, 8);
	for (auto item : tmp)
		std::cout << item << "\t";
	std::cout << "\n";
	return(0);
}