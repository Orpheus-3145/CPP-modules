/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 22:28:50 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:55:12 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << *this << " created" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << *this << " created" << std::endl;
}

FragTrap::FragTrap( FragTrap const& other ) : ClapTrap( other )
{
	std::cout << *this << " created" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << *this << " instance removed" << std::endl;
}

void	FragTrap::attack( ClapTrap& other)
{
	if (this->_energyPoints == 0)
		std::cout << *this << " cannot perform action: not enough energy points" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << *this << " cannot perform action: destroyed" << std::endl;
	else
	{
		std::cout << *this << " attacks with bad vibes " << other << ", causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
		other.takeDamage(this->_attackDamage);
		this->printInfo();
	}
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "positive high fives" << std::endl;
}

std::ostream&	FragTrap::present( std::ostream& os ) const
{
	os << "FragTrap " << this->getName();
	return (os);
}
