/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 20:15:41 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:21:42 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    this->_name = name;
    std::cout << "HumanA "  << this->_name << " created" << std::endl;

}

HumanA::~HumanA( void )
{
    std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void HumanA::attack ( void ) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
