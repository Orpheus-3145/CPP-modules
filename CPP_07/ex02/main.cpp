/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:08:41 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 21:24:49 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	// Array<int> test_arr1(12);
	Array<int> test_arr2(12);
	for(int i = 0; i < 12; i++)
		test_arr2[i] = i * -1;
	Array<int> test_arr1 = test_arr2;
	// for(int i = 0; i < 12; i++)
	// 	test_arr1[i] = i;
	for(int i = 0; i < 12; i++)
		test_arr1[i]++;
	// test_arr1[123];
	std::cout << "test_arr1" << std::endl;
	for(int i = 0; i < 12; i++)
		std::cout << test_arr1[i] << std::endl;
	std::cout << "test_arr2" << std::endl;
	for(int i = 0; i < 12; i++)
		std::cout << test_arr2[i] << std::endl;
	return 0;
}