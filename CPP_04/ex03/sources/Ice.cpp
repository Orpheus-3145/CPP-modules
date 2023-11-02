/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 16:11:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 19:32:25 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
}

Ice::Ice( std::string const& type ) : AMateria(type)
{
}

Ice::Ice( Ice const& other ) : AMateria(other)
{
}

Ice::~Ice( void )
{
}

AMateria*   Ice::clone() const 
{
	return(new Ice(*this));
}

void        Ice::use( ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
