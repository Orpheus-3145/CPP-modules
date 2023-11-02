/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:20:23 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:18:48 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	this->_type = "Cat";
	std::cout << "a new " << this->_type << " is born" << std::endl;
}

Cat::Cat( Cat const& other ) : Animal(other)
{
	std::cout << "a new " << this->_type << " is born" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "(child class) the " << this->_type << " is dead" << std::endl;
}

Cat& Cat::operator=(Cat const& other)
{
	if (this != &other)
		this->_type = other.getType();
	return(*this);
}

void Cat::makeSound (void ) const 
{
	std::cout << " ... (Cat sounds) ... " << std::endl;
}
