/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:20:23 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:19:26 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	this->_type = "Dog";
	std::cout << "a new " << this->_type << " is born" << std::endl;
}

Dog::Dog( Dog const& other ) : Animal(other)
{
	std::cout << "a new " << this->_type << " is born" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "(child class) the " << this->_type << " is dead" << std::endl;
}
Dog& Dog::operator=(Dog const& other)
{
	if (this != &other)
		this->_type = other.getType();
	return(*this);
}

void Dog::makeSound (void ) const 
{
	std::cout << " ... (Dog sounds) ... " << std::endl;
}
