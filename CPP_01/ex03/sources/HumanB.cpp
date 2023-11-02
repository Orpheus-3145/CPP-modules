/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 20:25:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:21:46 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
    std::cout << "HumanB "  << this->_name << " created" << std::endl;

}

HumanB::~HumanB( void )
{
    std::cout << "HumanB "  << this->_name << " destroyed" << std::endl;
}

void HumanB::attack( void ) const
{
    if (this->_weapon == NULL)
        std::cout << this->_name << " is disarmed" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &new_weapon)
{
    this->_weapon = &new_weapon;
}
