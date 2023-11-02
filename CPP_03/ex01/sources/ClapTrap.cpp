/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 20:40:24 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:56:10 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	this->_name = "no_name";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << *this << " created" << std::endl;
}

ClapTrap::ClapTrap( std::string const& name )
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << *this << " created" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const& other )
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << *this << " created" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << *this << " instance removed" << std::endl;
}

std::ostream&	ClapTrap::present( std::ostream& os ) const
{
	os << "ClapTrap " << this->getName();
	return (os);
}

std::string const&	ClapTrap::getName( void ) const 
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints( void ) const 
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints( void ) const 
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage( void ) const 
{
	return (this->_attackDamage);
}

void	ClapTrap::setName( std::string const& newName ) 
{
	this->_name = newName;
}

void	ClapTrap::setHitPoints( unsigned int newHitPoints )
{
	this->_hitPoints = newHitPoints;
}

void	ClapTrap::setEnergyPoints( unsigned int newEnergyPoints )
{
	this->_energyPoints = newEnergyPoints;
}

void	ClapTrap::setAttackDamage( unsigned int newAttackDamage )
{
	this->_attackDamage = newAttackDamage;
}

void	ClapTrap::attack( ClapTrap& other)
{
	if (this->_energyPoints == 0)
		std::cout << *this << " cannot perform action: not enough energy points" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << *this << " cannot perform action: destroyed" << std::endl;
	else
	{
		std::cout << *this << " attacks " << other << ", causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
		other.takeDamage(this->_attackDamage);
		this->printInfo();
	}
}

void	ClapTrap::takeDamage(unsigned int amount )
{
	if (this->_hitPoints == 0)
		std::cout << *this << " cannot perform action: destroyed"  << std::endl;
	else
	{
		std::cout << *this << " receives " << amount << " damage" << std::endl;
		if (this->_hitPoints > amount)
			this->_hitPoints -= amount;
		else
		{
			this->_hitPoints = 0;
			std::cout << *this << " is destroyed" << std::endl;
		}
		this->printInfo();
	}
}

void	ClapTrap::beRepaired(unsigned int amount )
{
	if (this->_energyPoints == 0)
		std::cout << *this << " cannot perform action: not enough energy points" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << *this << " cannot perform action: destroyed" << std::endl;
	else
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << *this << " repairs itself, gaining " << amount << " hit points" << std::endl;
		this->printInfo();
	}
}

void	ClapTrap::printInfo( void ) const
{
	std::cout << "------------------------" << std::endl 
		<< std::left << std::setw(15) << *this << std::endl 
		<< std::left << std::setw(15) << "hit points " << this->_hitPoints << std::endl 
		<< std::left << std::setw(15) << "energy points " << this->_energyPoints << std::endl
		<< std::left << std::setw(15) << "attack damage " << this->_attackDamage << std::endl
		<< std::left << std::setw(15) << "------------------------" << std::endl;
}

ClapTrap& 	ClapTrap::operator=( ClapTrap const& compare )
{
	if (this != &compare)
	{
		this->_name = compare.getName();
		this->_hitPoints = compare.getHitPoints();
		this->_energyPoints = compare.getEnergyPoints();
		this->_attackDamage = compare.getAttackDamage();
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, ClapTrap const& obj )
{
	return (obj.present(os));
}
