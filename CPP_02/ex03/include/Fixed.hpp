/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:29:33 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:36:33 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <iomanip>
# include <string>
# include <bitset>
# include <cmath>
# define DEC_BITS_FIXED 8
# define MAX_EXP (int) (powf(2.f, DEC_BITS_FIXED))
# define MAX_ELEMENT (int) (powf(2.f, (float) (32 - DEC_BITS_FIXED - 1)) - 1)
# define MIN_ELEMENT (int) (powf(2.f, (float) (32 - DEC_BITS_FIXED - 1)) * -1)
# define MAX_FIXED ((MAX_ELEMENT << DEC_BITS_FIXED) & (MAX_EXP - 1))
# define MIN_FIXED ((MIN_ELEMENT << DEC_BITS_FIXED) & (MAX_EXP - 1))

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const& );
		Fixed( int );
		Fixed( float );
		~Fixed ( void );

		static Fixed& 		min(Fixed&, Fixed&);
		static const Fixed& min(Fixed const&, Fixed const&);
		static Fixed& 		max(Fixed&, Fixed&);
		static const Fixed& max(Fixed const&, Fixed const&);

		int 			getRawBits( void ) const;
		void			setRawBits( int newValue);
		float 			toFloat( void ) const;
		int				toInt( void ) const;
		Fixed& 			operator=(const Fixed&) ;
		bool			operator<(const Fixed&) const ;
		bool			operator>(const Fixed&) const ;
		bool			operator<=(const Fixed&) const ;
		bool			operator>=(const Fixed&) const ;
		bool			operator==(const Fixed&) const ;
		bool			operator!=(const Fixed&) const ;
		Fixed			operator+(const Fixed&) const ;
		Fixed			operator-(const Fixed&) const ;
		Fixed			operator*(const Fixed&) const ;
		Fixed			operator/(const Fixed&) const ;
		Fixed&			operator++( void );
		Fixed			operator++( int );
		Fixed&			operator--( void );
		Fixed			operator--( int );

 	private:
		int	_value;
};

std::ostream&  operator<<(std::ostream&, const Fixed&);

#endif
