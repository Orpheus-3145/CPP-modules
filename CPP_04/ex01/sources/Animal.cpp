/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:06:50 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:35:31 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal( void )
{
	this->_type = "unicorn";
	this->_brain = new Brain();
	std::cout << "(animal constructor) a " << this->_type << " is born" << std::endl;
}
Animal::Animal( Animal const& other)
{
	this->_type = other.getType();
	*(this->_brain) = *other.getBrain();
	std::cout << "(animal constructor) a " << this->_type << " is born" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "(animal destructor) the " << this->_type << " is dead" << std::endl;
	delete this->_brain;
}

void	Animal::setType( std::string& newType)
{
	this->_type = newType;
}

std::string const&	Animal::getType( void ) const 
{
	return(this->_type);
}

Brain*	Animal::getBrain( void ) const 
{
	return(this->_brain);
}

void	Animal::setBrain( Brain const& other)
{
	*(this->_brain) = other;
}

void Animal::makeSound( void ) const 
{
	std::cout << " ... (" << this->_type << " sounds) ... " << std::endl;
}

Animal& Animal::operator=(Animal const& other)
{
	if (this != &other)
	{
		this->_type = other.getType();
		*(this->_brain) = *other.getBrain();
	}
	std::cout << "(animal) assignment operator called" << std::endl;
	return(*this);
}	