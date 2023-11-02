/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 15:59:49 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 21:11:55 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
{
	this->_type = "no_type";
	// std::cout << "new " << this->_type << " created" << std::endl;
}

AMateria::AMateria( std::string const& type )
{
	this->_type = type;
	// std::cout << "new " << this->_type << " created" << std::endl;
}

AMateria::AMateria( AMateria const& other )
{
	this->_type = other.getType();
	// std::cout << "new " << this->_type << " created" << std::endl;
}

AMateria::~AMateria( void )
{
	// std::cout << this << "(AMateria destructor) " << this->_type << " destroyed" << std::endl;
}

std::string const& AMateria::getType() const
{
	return(this->_type);
}

void	AMateria::setType( std::string const& newType )
{
	this->_type = newType;
}

void	AMateria::use( ICharacter& target )
{
	std::cout << this->_type << " does material stuff on " << target.getName() << std::endl;
}

AMateria& AMateria::operator=( AMateria const& newObj )
{
	if (this != &newObj)
		this->_type = newObj.getType();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, AMateria const& toPrint)
{
	os << toPrint.getType() << " material";
	return (os);
}
