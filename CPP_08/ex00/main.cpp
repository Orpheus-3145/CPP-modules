/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:34:20 by fra           #+#    #+#                 */
/*   Updated: 2023/10/21 04:44:47 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main( void )
{
	std::vector<int>	vectCont;
	std::list<int>		listCont;
	std::deque<int>		dequeCont;

	for(int i = 0; i < 20; i++)
		vectCont.push_back(i);
	try
	{
		easyfind<std::vector<int> >(vectCont, 7);
		std::cout << "element found" << std::endl;
	}
	catch(const FindException& err)
	{
		std::cerr << err.what() << std::endl;
	}
	for(int i = 0; i < 20; i++)
		listCont.push_back(i);
	try
	{
		easyfind<std::list<int> >(listCont, 28);
		std::cout << "element found" << std::endl;
	}
	catch(const FindException& err)
	{
		std::cerr << err.what() << std::endl;
	}
	for(int i = 0; i < 20; i++)
		dequeCont.push_back(i);
	try
	{
		easyfind<std::deque<int> >(dequeCont, 7);
		std::cout << "element found" << std::endl;
	}
	catch(const FindException& err)
	{
		std::cerr << err.what() << std::endl;
	}
    return 0;
}