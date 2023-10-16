/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:02:43 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 00:49:57 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> class Array
{
	public:
		Array( void ) ;
		Array( unsigned int ) throw(std::exception);
		Array( Array<T> const& ) throw(std::exception);
		~Array( void ) throw();
		Array<T>&	operator=( Array<T> const& ) throw(std::exception);
		Array<T>&		operator[]( int ) throw(std::exception);

		unsigned int	size( void ) const throw();

	private:
		T*				_items;
		unsigned int	nItems;
	
};

template <typename T> 
std::ostream&	operator<<(std::ostream& os, Array<T> element)
{
	for(int i = 0; i < element.size(); i++)
		os << "\t" << element[i] << std::endl;
	return (os);
}

#include "Array.tpp"