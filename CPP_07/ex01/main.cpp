/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:08:41 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 23:20:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void )
{
	int arr[5] = {123, 56, 4, 6 , 2};
	void (*intFunzPointer)(int&) = &funzia<int>;
	std::cout << "before" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << arr[i] << std::endl;
	iter<int>(arr, 5, intFunzPointer);
	std::cout << "after" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "\t" << arr[i] << std::endl;
	return 0;
}