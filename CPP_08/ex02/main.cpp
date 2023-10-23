/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 20:41:56 by fra           #+#    #+#                 */
/*   Updated: 2023/10/24 00:53:57 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <limits>
#include "MutantStack.hpp"

int main( void )
{
	MutantStack<int> tmp;
    std::random_device rd;
    std::mt19937 gen(rd());
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    std::uniform_int_distribution<int> dist(min, max);
    for (int i=0; i<1000; i++)
	{
        tmp.push(dist(gen));
	}
	for (auto iter : tmp)
		std::cout << iter << std::endl;
	return (0);
}