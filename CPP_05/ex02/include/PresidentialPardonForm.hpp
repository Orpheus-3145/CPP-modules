/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 20:33:10 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 22:11:31 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

namespace brt
{
	namespace forms
	{
		class PresidentialPardonForm;
	}
}

class brt::forms::PresidentialPardonForm : public brt::AForm
{
	public:
		PresidentialPardonForm( void ) throw() :
			brt::AForm("Presidential pardon", 25, 5) , _target("no_target") {}
		PresidentialPardonForm( std::string const& target) throw() :
			brt::AForm("Presidential pardon", 25, 5) , _target(target){}
		PresidentialPardonForm( brt::forms::PresidentialPardonForm const& other ) throw() :
			brt::AForm(other) , _target(other.getTarget()){}
		virtual ~PresidentialPardonForm( void ) throw() {};
		brt::forms::PresidentialPardonForm& operator=(brt::forms::PresidentialPardonForm const&) throw();

		std::string const&	getTarget( void ) const  throw();
		virtual void 		execute( void ) const throw();

	protected:
		std::string	_target;

};
#endif