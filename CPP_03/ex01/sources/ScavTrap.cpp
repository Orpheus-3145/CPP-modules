/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 22:28:50 by fra           #+#    #+#                 */
/*   Updated: 2023/10/06 03:30:01 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << *this << " created" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << *this << " created" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const& other ) : ClapTrap( other )
{
	std::cout << *this << " created" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << *this << " instance removed" << std::endl;
}

void	ScavTrap::attack( ClapTrap& other)
{
	if (this->_energyPoints == 0)
		std::cout << *this << " cannot perform action: not enough energy points" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << *this << " cannot perform action: destroyed" << std::endl;
	else
	{
		std::cout << *this << " attacks with a bat " << other << ", causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
		other.takeDamage(this->_attackDamage);
		this->printInfo();
	}
}

void ScavTrap::guardGate() const 
{
    std::cout << *this << " is guarding the gate" << std::endl;
}

std::ostream&	ScavTrap::present( std::ostream& os ) const
{
	os << "ScavTrap " << this->getName();
	return (os);
}
