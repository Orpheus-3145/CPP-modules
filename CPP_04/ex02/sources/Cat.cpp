/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:20:23 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 15:42:06 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : AbsAnimal()
{
	this->_type = "cat";
	std::cout << "(cat constructor) a new " << this->_type << " is born" << std::endl;
}

Cat::Cat( AbsAnimal const& other ) : AbsAnimal(other)
{
	std::cout << "(cat constructor) a new " << this->_type << " is born" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "(cat destructor) the " << this->_type << " is dead" << std::endl;
}

void Cat::makeSound (void ) const 
{
	std::cout << " ... (fuzzy " << this->_type << " sounds) ... " << std::endl;
}
