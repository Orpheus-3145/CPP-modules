/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:48:44 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:49:46 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int main( void ) 
{
	Point p1 = Point(0.5, 1.4);
	Point p2 = Point(5, 7.2);
	Point p3 = Point(3.2, -7.2);
	std::cout << "new triangle:\n\t" << p1 << "\n\t" << p2 << "\n\t" << p3 << std::endl;
	Point check = Point(3, 2);
	if (bsp(p1, p2, p3, check) == true)
		std::cout << "point: " << check << " is inside" << std::endl;
	else
		std::cout << "point: " << check << " is not inside" << std::endl;
	check = Point(4.95, 7.1);
	if (bsp(p1, p2, p3, check) == true)
		std::cout << "point: " << check << " is inside" << std::endl;
	else
		std::cout << "point: " << check << " is not inside" << std::endl;
	return 0;
}