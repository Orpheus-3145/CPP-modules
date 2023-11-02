/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:48:44 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:42:45 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed a(1), b(2);
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -1, b = -2;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -1, b = 2;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 1, b = -2;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -1.f, b = -2.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 1.f, b = -2.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -1.f, b = 2.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 1.f, b = 2.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;

	// a = -23, b = -7;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -23, b = 7;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 23, b = 67;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -23.f, b = -7.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 23.f, b = -7.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -23.f, b = 7.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 23.f, b = 7.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;

	// a = 423, b = 619;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -423, b = -619;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -423, b = 619;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 423, b = -619;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -423.f, b = -619.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 423.f, b = -619.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -423.f, b = 619.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 423.f, b = 619.f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -423.37f, b = -619.22f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 423.37f, b = -619.22f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = -423.37f, b = 619.22f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 423.37f, b = 619.22f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 3.01f, b = 9.01f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;
	// a = 3.88f, b = 9.88f;
	// std::cout << a << " / " << b << " = " << a / b <<std::endl;

	// a = 838860, b = 100;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	// a = 838860, b = 100;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	// a = -838860, b = -100;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	// a = -838860, b = -100;	
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	// a = -838860, b = -100;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;	
	// a = -838860, b = -100;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	// a = 838860, b = 838860;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	// a = -838860, b = -8388608;
	// std::cout << std::setprecision(10) << a << " * " << b << " = " << a * b <<std::endl;
	return 0;
}