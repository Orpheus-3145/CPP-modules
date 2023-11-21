/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:26:38 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 15:45:30 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <stdint.h>

typedef struct Data_s
{
	int	x;
	int	y;
	int	z;
} Data;

class Serializer
{
	public:
		virtual ~Serializer( void ) {}
		static uintptr_t	serialize( Data* ptr ) {return(reinterpret_cast<uintptr_t>(ptr));}
		static Data*		deserialize (uintptr_t raw ) {return(reinterpret_cast<Data*>(raw));}

	private:
		Serializer( void ) {}
		Serializer( Serializer const& ) {}
		Serializer& operator=( Serializer const& ) {return (*this);}
};

#endif
