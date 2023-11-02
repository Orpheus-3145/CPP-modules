/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:20:23 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:41:12 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	this->_type = "dog";
	std::cout << "(dog constructor) a new " << this->_type << " is born" << std::endl;
}

Dog::Dog( Animal const& other ) : Animal(other)
{
	std::cout << "(dog constructor) a new " << this->_type << " is born" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "(dog destructor) the " << this->_type << " is dead" << std::endl;
}

void Dog::makeSound (void ) const 
{
	std::cout << " ... (doggish " << this->_type << " sounds) ... " << std::endl;
}