/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:08:41 by fra           #+#    #+#                 */
/*   Updated: 2023/11/21 19:58:57 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "Array.hpp"

// int main( void )
// {
// 	// Array<int> test_arr1(12);
// 	Array<int> test_arr2(12);
// 	for(int i = 0; i < 12; i++)
// 		test_arr2[i] = i * -1;
// 	Array<int> test_arr1 = test_arr2;
// 	// for(int i = 0; i < 12; i++)
// 	// 	test_arr1[i] = i;
// 	for(int i = 0; i < 12; i++)
// 		test_arr1[i]++;
// 	// test_arr1[123];
// 	std::cout << "test_arr1" << std::endl;
// 	for(int i = 0; i < 12; i++)
// 		std::cout << test_arr1[i] << std::endl;
// 	std::cout << "test_arr2" << std::endl;
// 	for(int i = 0; i < 12; i++)
// 		std::cout << test_arr2[i] << std::endl;
// 	return 0;
// }

#include <iostream>
# include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}