/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:37:10 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:52:18 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed& 		Fixed::min(Fixed& a, Fixed& b)
{
	int bitA;
	int bitB;
	int cnt = 31;
	while (cnt != 0)
	{
		bitA = (a.getRawBits() >> cnt) & 1;
		bitB = (b.getRawBits() >> cnt) & 1;
		if (bitA ^ bitB)
			return((bitA == 1) ? b : a);
		cnt--;
	}
	return (a);	
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b )
{
	int bitA;
	int bitB;
	int cnt = 31;
	while (cnt != 0)
	{
		bitA = (a.getRawBits() >> cnt) & 1;
		bitB = (b.getRawBits() >> cnt) & 1;
		if (bitA ^ bitB)
			return((bitA == 1) ? b : a);
		cnt--;
	}
	return (a);
}

Fixed& 		Fixed::max(Fixed& a, Fixed& b)
{
	if (Fixed::min(a, b) == b)
		return(a);
	else
		return(b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b )
{
	const Fixed tmpMin = min(a, b);
	if (tmpMin.getRawBits() == a.getRawBits())
		return (b);
	else
		return (a);
}

Fixed::Fixed( void )
{
	this->_value = 0;
}

Fixed::Fixed( Fixed const& other )
{
	this->_value = other.getRawBits();
}

Fixed::Fixed( int value )
{
	if (value > MAX_ELEMENT)
		value = MIN_ELEMENT;
	else if (value < MIN_ELEMENT)
		value = MAX_ELEMENT;
	this->_value = value * MAX_EXP;
}

Fixed::Fixed( float value )
{
	if ((int) value > MAX_ELEMENT)
		value = MIN_ELEMENT;
	else if ((int) value < MIN_ELEMENT)
		value = MAX_ELEMENT;
	this->_value = (int) roundf(value * MAX_EXP);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int     Fixed::getRawBits( void ) const
{
	return(this->_value);
}

void    Fixed::setRawBits( int newValue )
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
	if (this != &compare)
		this->_value = compare.getRawBits();
	return (*this);
}

bool	Fixed::operator<(Fixed const& to_check ) const
{
	return(this->_value < to_check.getRawBits());
}

bool	Fixed::operator>(Fixed const& to_check ) const
{
	return(this->_value > to_check.getRawBits());
}

bool	Fixed::operator<=(Fixed const& to_check ) const
{
	return(this->_value <= to_check.getRawBits());
}

bool	Fixed::operator>=(Fixed const& to_check ) const
{
	return(this->_value >= to_check.getRawBits());
}

bool	Fixed::operator==(Fixed const& to_check ) const
{
	return(this->_value == to_check.getRawBits());
}

bool	Fixed::operator!=(Fixed const& to_check ) const
{
	return(! (*this == to_check));
}

Fixed	Fixed::operator+( Fixed const& other ) const
{
	Fixed	sumObj;
	int 	sum = this->_value + other.getRawBits();

	sumObj.setRawBits(sum);
	return (sumObj);
}

Fixed	Fixed::operator-( Fixed const& other ) const
{
	Fixed	tmp = other * Fixed(-1);
	return (*this + tmp);
}

Fixed	Fixed::operator*( Fixed const& other ) const
{
	float	tmp1 = this->_value / powf(2.f, (float) DEC_BITS_FIXED / 2.f);
	float	tmp2 = other.getRawBits() / powf(2.f, (float) DEC_BITS_FIXED / 2.f);
	float	prod = (tmp1 * tmp2) / powf(2.f, (DEC_BITS_FIXED % 2) ? 1 : 0);
	Fixed	prodObj;

	prodObj.setRawBits(prod);
	return (prodObj);
}

Fixed	Fixed::operator/( Fixed const& other ) const
{
	float quot = ((float) this->_value) / ((float) other.getRawBits());
	return (Fixed(quot));
}

Fixed&	Fixed::operator++( void )
{
	if (this->toInt() != (MAX_ELEMENT - 1))
		this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++( int  other )
{
	Fixed	tmp = Fixed(*this);
	++(*this);
	other++;
	return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	if (this->toInt() != (MAX_ELEMENT * -1))
		this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int  other )
{
	Fixed	tmp = Fixed(*this);
	--(*this);
	other++;
	return (tmp);
}

std::ostream&  operator<<( std::ostream& os, const Fixed& obj )
{
	os << obj.toFloat();
	return (os);
}
