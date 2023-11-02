/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 20:55:45 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 21:09:39 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for(int i=0; i<MateriaSource::_maxItems; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const& other)
{
	AMateria const* newMaterial;

	for(int i=0; i<MateriaSource::_maxItems; i++)
	{
		newMaterial = other.getMaterial(i);
		if (newMaterial == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = newMaterial->clone();
	}
}

MateriaSource::~MateriaSource( void )
{
	for(int i=0; i<MateriaSource::_maxItems; i++)
		delete this->_inventory[i];
}

MateriaSource& MateriaSource::operator=( MateriaSource const& other)
{
	AMateria const* newMaterial;

	if (this != &other)
	{
		for(int i=0; i<MateriaSource::_maxItems; i++)
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
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* newSource)
{
	for (int i=0; i<MateriaSource::_maxItems; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = newSource;
			break ;
		}
	}
}

AMateria* 	MateriaSource::createMateria(std::string const& type)
{
	for (int i=0; i<MateriaSource::_maxItems; i++)
	{
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}

AMateria const*		MateriaSource::getMaterial( int index) const 
{
	if ((index >= 0) and (index < MateriaSource::_maxItems))
		return(this->_inventory[index]);
	else
		return (NULL);
}	
