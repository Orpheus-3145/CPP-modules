/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 19:26:14 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 20:35:29 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

brt::AForm*	brt::Intern::makeForm( std::string const& nameForm, std::string const& target ) const 
	throw()
{
	std::map<std::string const, brt::AForm* (*)(std::string const&)> classMap;

    classMap["presForm"] = &(brt::forms::PresidentialPardonForm::newInstance);
    classMap["robotForm"] = &(brt::forms::RobotomyRequestForm::newInstance);
    classMap["ShrubForm"] = &(brt::forms::ShrubberyCreationForm::newInstance);
    if (classMap.find(nameForm) != classMap.end())
	{
        std::cout << "Intern creates " << nameForm << std::endl;
        return (classMap[nameForm](target));
	}
    else
	{
        std::cout << "Class not found for name: " << nameForm << std::endl;
		return (NULL);
	}
}
