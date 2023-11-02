/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 01:30:54 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:56:24 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("no_name_clap_name") , ScavTrap() , FragTrap()
{
	this->_name = "no_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << *this << " created" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const& name ) : ClapTrap(name + "_clap_name"), ScavTrap() , FragTrap()
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << *this << " created" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const& other ) : ClapTrap(other) , ScavTrap(other) , FragTrap(other)
{
	std::cout << *this << " created" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << *this << " instance removed" << std::endl;
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout << "ClapTrap name: " << ClapTrap::_name << " " << *this << std::endl;
}

void	DiamondTrap::printInfo( void ) const
{
	std::cout << "------------------------" << std::endl 
		<< std::left << std::setw(18) << "DiamonTrap name: " << this->_name << std::endl
		<< std::left << std::setw(18) << "ClapTrap name: " << ClapTrap::_name << std::endl
		<< std::left << std::setw(18) << "hit points: " << this->_hitPoints << std::endl 
		<< std::left << std::setw(18) << "energy points: " << this->_energyPoints << std::endl
		<< std::left << std::setw(18) << "attack damage: " << this->_attackDamage << std::endl
		<< "------------------------" << std::endl;
}

std::ostream&	DiamondTrap::present( std::ostream& os ) const
{
	os << "DiamondTrap " << this->_name;
	return (os);
}

void	DiamondTrap::attack( ClapTrap& other )
{
	ScavTrap::attack(other);
}
