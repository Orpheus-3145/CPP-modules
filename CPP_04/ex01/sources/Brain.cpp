/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 16:43:18 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:38:24 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "no idea";
	std::cout << "(brain constructor) brain created" << std::endl;
}

Brain::Brain( std::string* ideas)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
	std::cout << "(brain constructor) brain created" << std::endl;
}

Brain::Brain( Brain const& other )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other.getIdeas()[i];
	std::cout << "(brain constructor) brain created" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "(brain destructor) brain destroyed" << std::endl;
}

Brain& Brain::operator=( Brain const& other )
{
	std::cout << "(brain) assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other.getIdeas()[i];
	return (*this);
}

std::string const*	Brain::getIdeas( void ) const
{
	return(this->_ideas);
}

void	Brain::setIdeas( std::string const* newIdeas )
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = newIdeas[i];
}

void	Brain::printIdeas( void ) const
{
	for(int i = 0; i < 100; i++)
		std::cout << "--> " << this->_ideas[i] << std::endl;
}
