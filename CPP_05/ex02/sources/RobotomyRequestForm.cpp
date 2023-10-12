/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:08:29 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 00:38:35 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

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
	std::cout << " ... some drilling noises ..." << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomization has failed" << std::endl;
}