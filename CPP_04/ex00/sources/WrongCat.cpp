/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:20:23 by fra           #+#    #+#                 */
/*   Updated: 2023/10/09 15:24:36 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) :WrongAnimal()
{
	this->_type = "cat";
	std::cout << "a wrong new cat is born" << std::endl;
}

WrongCat::WrongCat( WrongAnimal const& other )
{
	this->_type = other.getType();
	std::cout << "a wrong cat is born" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "the wrong cat is dead" << std::endl;
}

void WrongCat::makeSound (void ) const 
{
	std::cout << " ... (wrong cat sounds) ... " << std::endl;
}
