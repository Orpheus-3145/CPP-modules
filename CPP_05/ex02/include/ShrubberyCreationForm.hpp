/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:10:19 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 00:31:29 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

namespace brt
{
	namespace forms
	{
		class ShrubberyCreationForm;
	}
}

class brt::forms::ShrubberyCreationForm : public brt::AForm
{
	public:
		ShrubberyCreationForm( void ) throw() :
			brt::AForm("Shrubbery creation ", 145, 137) , _target("no_target") {}
		ShrubberyCreationForm( std::string const& target) throw() :
			brt::AForm("Shrubbery creation ", 145, 137) , _target(target){}
		ShrubberyCreationForm( brt::forms::ShrubberyCreationForm const& other ) throw() :
			brt::AForm(other) , _target(other.getTarget()){}
		virtual ~ShrubberyCreationForm( void ) throw() {};
		brt::forms::ShrubberyCreationForm& operator=(brt::forms::ShrubberyCreationForm const&) throw();

		std::string const&	getTarget( void ) const  throw();
		virtual void 		execute( void ) const throw(brt::GenericException);

	protected:
		std::string	_target;

};

#endif