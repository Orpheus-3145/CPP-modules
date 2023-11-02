/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 23:37:46 by fra           #+#    #+#                 */
/*   Updated: 2023/10/04 22:02:38 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( float const, float const );
		Point( Fixed const, Fixed const );
		Point( Point const& );
		~Point( void );
		Fixed		   	getX( void ) const ;
		Fixed		   	getY( void ) const ;
		Point const&	operator=(const Point&);
		bool			operator==(const Point&) const ;
		bool			operator!=(const Point&) const ;

	private:
		Fixed _x;
		Fixed _y;
};

std::ostream&  operator<<(std::ostream&, const Point&);

bool bsp( Point const, Point const, Point const, Point const );

#endif