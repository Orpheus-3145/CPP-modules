/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 19:19:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:13:07 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
    this->_type = "empty hands";
    std::cout << "Weapon " << this->_type << " created " << this << std::endl;
}

Weapon::Weapon( std::string type )
{
    this->_type = type;
    std::cout << "Weapon " << this->_type << " created " << std::endl;
}

Weapon::~Weapon( void )
{
    std::cout << "Weapon " << this->_type << " destroyed " << std::endl;
}

const std::string& Weapon::getType( void ) const
{
    return (this->_type);
}

void Weapon::setType(std::string const& type)
{
    this->_type = type;
}
