/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AbsAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:06:50 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:47:24 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"
#include "Brain.hpp"

AbsAnimal::AbsAnimal( void )
{
	this->_type = "unicorn";
	this->_brain = new Brain();
	std::cout << "(animal constructor) a " << this->_type << " is born" << std::endl;
}
AbsAnimal::AbsAnimal( AbsAnimal const& other)
{
	this->_type = other.getType();
	*(this->_brain) = *other.getBrain();
	std::cout << "(animal constructor) a " << this->_type << " is born" << std::endl;
}

AbsAnimal::~AbsAnimal( void )
{
	std::cout << "(animal destructor) the " << this->_type << " is dead" << std::endl;
	delete this->_brain;
}

void	AbsAnimal::setType( std::string& newType)
{
	this->_type = newType;
}

std::string const&	AbsAnimal::getType( void ) const 
{
	return(this->_type);
}

Brain*	AbsAnimal::getBrain( void ) const 
{
	return(this->_brain);
}

void	AbsAnimal::setBrain( Brain const& other)
{
	*(this->_brain) = other;
}

// void AbsAnimal::makeSound( void ) const 
// {
// 	std::cout << " ... (" << this->_type << " sounds) ... " << std::endl;
// }

AbsAnimal& AbsAnimal::operator=(AbsAnimal const& other)
{
	if (this != &other)
	{
		this->_type = other.getType();
		*(this->_brain) = *other.getBrain();
	}
	std::cout << "(animal) assignment operator called" << std::endl;
	return(*this);
}	