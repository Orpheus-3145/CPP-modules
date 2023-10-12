/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:08:29 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 22:09:44 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

brt::forms::RobotomyRequestForm& brt::forms::RobotomyRequestForm::operator=(brt::forms::RobotomyRequestForm const& other) throw()
{
	if (this != &other)
	{
		this->_target = other.getTarget();
		*this = other;
	}
	return (*this);
}

std::string const&	brt::forms::RobotomyRequestForm::getTarget( void ) const throw()
{
	return (this->_target);
}

void 	brt::forms::RobotomyRequestForm::execute( void ) const throw()
{
	
}