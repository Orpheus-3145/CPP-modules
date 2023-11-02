/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:06:50 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:18:55 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	this->_type = "Unicorn";
	std::cout << "a new " << this->_type << " is born" << std::endl;
}
Animal::Animal( Animal const& other)
{
	this->_type = other.getType();
	std::cout << "a new " << this->_type << " is born" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "(parent class) the " << this->_type << " is dead" << std::endl;
}

void	Animal::setType( std::string& newType)
{
	this->_type = newType;
}

std::string const&	Animal::getType( void ) const 
{
	return(this->_type);
}

void Animal::makeSound( void ) const 
{
	std::cout << " ... (Unicorn sounds) ... " << std::endl;
}

Animal& Animal::operator=(Animal const& other)
{
	if (this != &other)
		this->_type = other.getType();
	return(*this);
}