/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:08:41 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 00:50:06 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void )
{
	Array<int> test_arr(12);
	for(int i = 0; i < 12; i++)
		test_arr[i] = i;
	for(int i = 0; i < 12; i++)
		std::cout << test_arr[i] << std::endl;
	return 0;
}