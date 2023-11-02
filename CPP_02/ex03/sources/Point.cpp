/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 23:34:23 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:52:12 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void )
{
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point( float const x, float const y )
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::Point( Fixed const x, Fixed const y )
{
	this->_x = x;
	this->_y = y;
}

Point::Point( Point const& other )
{
	this->_x = other.getX();
	this->_y = other.getY();
}

Point::~Point( void )
{
	std::cout << "point destructed " << std::endl;
}

Fixed     Point::getX( void ) const
{
	return (this->_x);
}

Fixed     Point::getY( void ) const
{
	return (this->_y);
}

Point const&    Point::operator=( Point const& other )
{
	if (this != &other) 
	{
		this->_x = other.getX();
		this->_y = other.getY();
	}
	return (*this);
}

bool    Point::operator==(const Point& other ) const
{
	return ((this->getX() == other.getX()) and (this->getY() == other.getY()));
}

bool    Point::operator!=(const Point& other ) const
{
	return (! (*this == other));
}

std::ostream&  operator<<( std::ostream& os, const Point& obj )
{
	os << "x: " << obj.getX() << " y: " << obj.getY();
	return (os);
}
