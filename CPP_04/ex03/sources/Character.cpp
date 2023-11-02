/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 16:50:31 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 23:40:52 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void )
{
	this->_name = "no_name";
	for(int i=0; i<Character::_maxItems; i++)
		this->_inventory[i] = NULL;
	for(int i=0; i<Character::_maxFloorItems; i++)
		this->_floor[i] = NULL;
	// std::cout << *this << " created" << std::endl;
}

Character::Character( std::string const& newName)
{
	this->_name = newName;
	for(int i=0; i<Character::_maxItems; i++)
		this->_inventory[i] = NULL;
	for(int i=0; i<Character::_maxFloorItems; i++)
		this->_floor[i] = NULL;
	// std::cout << *this << " created" << std::endl;
}

Character::Character( Character const& other)
{
	AMateria const* newMaterial;

	this->_name = other.getName();
	for(int i=0; i<Character::_maxItems; i++)
	{
		newMaterial = other.getMaterial(i);
		if (newMaterial == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = newMaterial->clone();
	}
	for(int i=0; i<Character::_maxFloorItems; i++)
		this->_floor[i] = NULL;
	// std::cout << *this << " created" << std::endl;
}

Character::~Character( void )
{
	for(int i=0; i<Character::_maxItems; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		else
			break;
	}
	for(int i=0; i<Character::_maxFloorItems; i++)
	{
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
		else
			break;
	}
	// std::cout << *this << " destroyed" << std::endl;
}

void	Character::showInventory( void ) const
{
	for(int i=0; i<Character::_maxItems; i++)
	{
		std::cout << i << ") ";
		if (this->_inventory[i] != NULL)
			std::cout << *(this->_inventory[i]) << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
}

void	Character::addEleToFloor( AMateria* toAdd )
{
	for (int i=0; i<Character::_maxFloorItems; i++)
	{
		if (this->_floor[i] == NULL)
		{
			this->_floor[i] = toAdd;
			break ;
		}
	}
}

AMateria const* Character::getMaterial( int index ) const 
{
	if ((index >= 0) and (index < Character::_maxItems))
		return(this->_inventory[index]);
	else
		return (NULL);
}

void	Character::setName( std::string const& newName )
{
	this->_name = newName;
}

std::string const& 	Character::getName( void ) const 
{
	return (this->_name);
}

void 	Character::equip( AMateria* newEquip)
{
	for (int i=0; i<Character::_maxItems; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = newEquip;
			break ;
		}
	}
}

void 	Character::unequip( int index )
{
	if ((index >= 0) and (index < Character::_maxItems) and (this->_inventory[index] != NULL))
	{
		this->addEleToFloor(this->_inventory[index]);
		this->_inventory[index] = NULL;
	}
}

void 	Character::use( int index, ICharacter& person )
{
	if ((index >= 0) and (index < Character::_maxItems) and (this->_inventory[index] != NULL))
		this->_inventory[index]->use(person);
}

Character& Character::operator=( Character const& other )
{
	AMateria const* newMaterial;

	if (this != &other)
	{
		this->_name = other.getName();
		for(int i=0; i<Character::_maxItems; i++)
		{
			newMaterial = other.getMaterial(i);
			if (newMaterial == NULL)
				this->_inventory[i] = NULL;
			else
			{
				delete this->_inventory[i];	
				this->_inventory[i] = newMaterial->clone();
			}
		}
		for(int i=0; i<Character::_maxFloorItems; i++)
		{
			if (this->_floor[i] != NULL)
				delete this->_floor[i];	
			this->_floor[i] = NULL;
		}
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Character const& other )
{
	os << "character " << other.getName();
	return (os);
}
