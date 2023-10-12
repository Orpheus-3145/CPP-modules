/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:09:02 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 22:09:41 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

brt::forms::ShrubberyCreationForm& brt::forms::ShrubberyCreationForm::operator=(brt::forms::ShrubberyCreationForm const& other) throw()
{
	if (this != &other)
	{
		this->_target = other.getTarget();
		*this = other;
	}
	return (*this);
}

std::string const&	brt::forms::ShrubberyCreationForm::getTarget( void ) const throw()
{
	return (this->_target);
}

void 	brt::forms::ShrubberyCreationForm::execute( void ) const throw()
{
	
}