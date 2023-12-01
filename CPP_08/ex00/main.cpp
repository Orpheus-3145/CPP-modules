/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:34:20 by fra           #+#    #+#                 */
/*   Updated: 2023/12/01 12:17:28 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyFind.hpp"

template <typename T> void testContainer(T const& container, int toFind)
{
	try
	{
		easyFind(container, toFind);
		std::cout << "element "<< toFind << " found" << std::endl;
	}
	catch(const FindException& err)
	{
		std::cerr << err.what() << std::endl;
	}
}

int main( void )
{
	int						toFind = 19;
	std::vector<int>		vectCont;
	std::list<int>			listCont;
	std::forward_list<int>	f_listCont;
	std::deque<int>			dequeCont;
	std::array<int, 20>		arrayCont;

	for(int i = 0; i < 20; i++)
		vectCont.push_back(i);
	for(int i = 0; i < 20; i++)
		listCont.push_back(i);
	for(int i = 0; i < 20; i++)
		f_listCont.push_front(i);
	for(int i = 0; i < 20; i++)
		dequeCont.push_back(i);
	for(int i = 0; i < 20; i++)
		arrayCont[i] = i;
	testContainer(vectCont, toFind);
	testContainer(listCont, toFind);
	testContainer(f_listCont, toFind);
	testContainer(dequeCont, toFind);
	testContainer(arrayCont, toFind);
	int test[20];
	testContainer(test, toFind);
    return 0;
}