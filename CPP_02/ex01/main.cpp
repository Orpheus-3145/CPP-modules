/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:48:44 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:37:40 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a_sub;
	Fixed const b_sub( 10 );
	Fixed const c_sub( 42.42f );
	Fixed const d_sub( b_sub );
	a_sub = Fixed( 1234.4321f );
	std::cout << "a is " << a_sub << std::endl;
	std::cout << "b is " << b_sub << std::endl;
	std::cout << "c is " << c_sub << std::endl;
	std::cout << "d is " << d_sub << std::endl;
	std::cout << "a is " << a_sub.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b_sub.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c_sub.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d_sub.toInt() << " as integer" << std::endl;

	// int a;
	// float b;
	// a = -125 ;
	// Fixed i = Fixed(a );
	// std::cout << a << " -- i is " << i << std::endl;
	// b = 125.56f ;
	// Fixed h = Fixed(b );
	// std::cout << b << " -- h is " << h << std::endl;
	// b = 73589.112f;
	// Fixed j = Fixed(b );
	// std::cout << b << " -- j is " << j << std::endl;
	// b = 789.128f;
	// Fixed f = Fixed(b );
	// std::cout << b << " -- f is " << f << std::endl;
	// b = -789.128f;
	// Fixed l = Fixed(b );
	// std::cout << b << " -- l is " << l << std::endl;
	// b = -9.101f;
	// Fixed m = Fixed(b );
	// std::cout << b << " -- m is " << m << std::endl;
	// b = 739.486f;
	// Fixed n = Fixed(b );
	// std::cout << b << " -- n is " << n << std::endl;
	// a = 73589112;
	// Fixed o = Fixed(b );
	// std::cout << b << " -- o is " << std::setprecision(5) << o << std::endl;
	// b = 73589.964f;
	// Fixed p = Fixed(b );
	// std::cout << b << " -- p is " << p << std::endl;
	// b = 0.964f;
	// Fixed q = Fixed(b );
	// std::cout << b << " -- q is " << q << std::endl;
	// b = 7.964f;
	// Fixed r = Fixed(b );
	// std::cout << b << " -- r is " << r << std::endl;
	// a = 0 ;
	// Fixed s = Fixed(a );
	// std::cout << a << " -- s is " << s << std::endl;
	// a = -1 ;
	// Fixed t = Fixed(a );
	// std::cout << a << " -- t is " << t << std::endl;
	// b = 75687.64f;
	// Fixed w = Fixed(b );
	// std::cout << b << " -- w is " << w << std::endl;
	// a = 1 ;
	// Fixed u = Fixed(a );
	// std::cout << a << " -- u is " << u << std::endl;
	// b = 77.11231f;
	// Fixed v = Fixed(b );
	// std::cout << b << " -- v is " << v << std::endl;
	return (0);
}
