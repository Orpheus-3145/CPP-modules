/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 16:34:21 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 19:32:43 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
}

Cure::Cure( std::string const& type ) : AMateria(type)
{
}

Cure::Cure( Cure const& other ) : AMateria(other)
{
}

Cure::~Cure( void )
{
}

AMateria*   Cure::clone() const 
{
	return(new Cure(*this));
}

void        Cure::use( ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
