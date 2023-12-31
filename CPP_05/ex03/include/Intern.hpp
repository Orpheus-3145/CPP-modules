/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 19:22:46 by fra           #+#    #+#                 */
/*   Updated: 2023/10/14 01:57:47 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HP
# define INTERN_HPP
# include <iostream>
# include <map>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

namespace brt
{
	class Intern;
}

class brt::Intern
{
	public:
		Intern ( void ) throw() {}
		Intern ( brt::Intern const& ) throw() {}
		virtual ~Intern( void ) throw() {}
		Intern& operator=( Intern const& ) throw() {return (*this);}
		brt::AForm*	makeForm( std::string const&, std::string const& ) const 
			throw();
};

#endif
