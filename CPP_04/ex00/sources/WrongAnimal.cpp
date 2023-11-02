/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:06:50 by fra           #+#    #+#                 */
/*   Updated: 2023/10/09 15:26:19 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	this->_type = "Unicorn";
	std::cout << "a wrong unicorn is born" << std::endl;
}
WrongAnimal::WrongAnimal( WrongAnimal const& other)
{
	this->_type = other.getType();
	std::cout << "a wrong unicorn is born" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "the wrong unicorn is dead" << std::endl;
}

void	WrongAnimal::setType( std::string& newType)
{
	this->_type = newType;
}

std::string const&	WrongAnimal::getType( void ) const 
{
	return(this->_type);
}

void WrongAnimal::makeSound( void ) const 
{
	std::cout << " ... (wrong unicorn sounds) ... " << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other)
{
	this->_type = other.getType();
	return(*this);
}