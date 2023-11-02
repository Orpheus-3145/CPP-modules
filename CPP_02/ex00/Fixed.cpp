/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:37:10 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:15:30 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
    this->_value = 0;
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& other)
{
    this->_value = other.getRawBits();
    std::cout << "copy constructor called" << std::endl;

}

Fixed::~Fixed ( void )
{
    std::cout << "destructor called" << std::endl;
}

Fixed& 	Fixed::operator=(Fixed const& compare)
{
    this->_value = compare.getRawBits();
    std::cout << "assignment operator called" << std::endl;
    return (*this);
}

int     Fixed::getRawBits( void ) const
{

    std::cout << "getRawBits member function called" << std::endl;
    return(this->_value);
}

void    Fixed::setRawBits( int newValue)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = newValue;
}
