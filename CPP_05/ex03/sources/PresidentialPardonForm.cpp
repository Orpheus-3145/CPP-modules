/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 20:54:57 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 20:48:41 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

brt::forms::PresidentialPardonForm& brt::forms::PresidentialPardonForm::operator=(brt::forms::PresidentialPardonForm const& other) throw()
{
	if (this != &other)
	{
		this->_target = other.getTarget();
		*this = other;
	}
	return (*this);
}

std::string const&	brt::forms::PresidentialPardonForm::getTarget( void ) const throw()
{
	return (this->_target);
}

void 	brt::forms::PresidentialPardonForm::execute( void ) const throw()
{
	std::cout << "Zaphod Beeblebrox has pardoned " << this->_target << std::endl;
}

brt::AForm*	brt::forms::PresidentialPardonForm::PresidentialPardonForm::newInstance( std::string const& target)
{
	return (new brt::forms::PresidentialPardonForm(target));
}