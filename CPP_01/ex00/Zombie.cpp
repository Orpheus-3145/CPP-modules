/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 16:35:05 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 15:14:46 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->_name = "";
}

Zombie::Zombie( std::string name)
{
	this->_name = name;
}

Zombie::~Zombie( void)
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

		