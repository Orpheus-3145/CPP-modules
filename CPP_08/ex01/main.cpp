/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 19:34:20 by fra           #+#    #+#                 */
/*   Updated: 2023/10/23 19:49:09 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <array>
#include <limits>
#include "Span.hpp"
#define MAX_ELEMENTS 50000

template <int nNumbers>
std::array<int, nNumbers> generateNumbers( bool doubleSign )
{
    std::array<int, nNumbers> container;
    std::random_device rd;
    std::mt19937 gen(rd());
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    if (doubleSign == false)
        min = 0;
    std::uniform_int_distribution<int> dist(min, max);
    for (int i=0; i<nNumbers; i++)
        container[i] = dist(gen);
    return (container);
}

int main( void )
{
    std::array<int, MAX_ELEMENTS> tmp = generateNumbers<MAX_ELEMENTS>(true);
    Span newSpan(MAX_ELEMENTS);
    newSpan.addMultipleNumbers(tmp.begin(), tmp.end());
    // newSpan.printSpan();
    std::cout << "size: " << newSpan.getItems().size() << std::endl;
    std::cout << "shortest span: " << newSpan.shortestSpan() << std::endl;
    std::cout << "longest span: " << newSpan.longestSpan() << std::endl;
    return 0;
}