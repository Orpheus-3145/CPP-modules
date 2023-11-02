/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:37:10 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:35:29 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_value = 0;
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& other )
{
	this->_value = other.getRawBits();
	std::cout << "copy constructor called" << std::endl;

}

Fixed::Fixed( int value )
{
	if (value > MAX_ELEMENT)
		value = MIN_ELEMENT;
	else if (value < MIN_ELEMENT)
		value = MAX_ELEMENT;
	this->_value = value * MAX_EXP;
	std::cout << "integer constructor called" << std::endl;
}

Fixed::Fixed( float value )
{
	if ((int) value > MAX_ELEMENT)
		value = MIN_ELEMENT;
	else if ((int) value < MIN_ELEMENT)
		value = MAX_ELEMENT;
	this->_value = (int) roundf(value * MAX_EXP);
	std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
	return(this->_value);
}

void    Fixed::setRawBits( int newValue)
{
	this->_value = newValue;
}

float 	Fixed::toFloat( void ) const
{
	return (((float) this->_value) / ((float) MAX_EXP));
}

int		Fixed::toInt( void ) const
{
	return(this->_value >> DEC_BITS_FIXED);
}

Fixed& 	Fixed::operator=( Fixed const& compare )
{
	this->_value = compare.getRawBits();
	std::cout << "assignment operator called" << std::endl;
	return (*this);
}

std::ostream&  operator<<( std::ostream& os, const Fixed& obj )
{
	os << obj.toFloat();
	return (os);
}
