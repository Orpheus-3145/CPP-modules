/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/01 02:29:33 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 17:37:52 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
	public:
		Fixed( void);
		Fixed( Fixed const&);
		~Fixed (void);
		Fixed& 	operator=(const Fixed&);
		int 	getRawBits( void ) const;
		void	setRawBits( int newValue);

 	private:
		int	_value;

};

#endif