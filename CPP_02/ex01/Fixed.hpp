/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:29:33 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:39:31 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# define DEC_BITS_FIXED 8
# define MAX_EXP (int) (powf(2.f, DEC_BITS_FIXED))
# define MAX_ELEMENT (int) (powf(2.f, (float) (32 - DEC_BITS_FIXED - 1)) - 1)
# define MIN_ELEMENT (int) (powf(2.f, (float) (32 - DEC_BITS_FIXED - 1)) * -1)
# define MAX_FIXED ((MAX_ELEMENT << DEC_BITS_FIXED) & (MAX_EXP - 1))
# define MIN_FIXED ((MIN_ELEMENT << DEC_BITS_FIXED) & (MAX_EXP - 1))
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const& );
		Fixed( int );
		Fixed( float );
		~Fixed ( void );
		int 			getRawBits( void ) const;
		void			setRawBits( int newValue);
		float 			toFloat( void ) const;
		int				toInt( void ) const;
		Fixed& 			operator=(const Fixed&);

 	private:
		int	_value;

};

std::ostream&  operator<<(std::ostream&, const Fixed&);

#endif