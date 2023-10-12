/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:06:51 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 22:11:47 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

namespace brt
{
	namespace forms
	{
		class RobotomyRequestForm;
	}
}

class brt::forms::RobotomyRequestForm : public brt::AForm
{
	public:
		RobotomyRequestForm( void ) throw() :
			brt::AForm("Presidential pardon", 72, 45) , _target("no_target") {}
		RobotomyRequestForm( std::string const& target) throw() :
			brt::AForm("Presidential pardon", 72, 45) , _target(target){}
		RobotomyRequestForm( brt::forms::RobotomyRequestForm const& other ) throw() :
			brt::AForm(other) , _target(other.getTarget()){}
		virtual ~RobotomyRequestForm( void ) throw() {};
		brt::forms::RobotomyRequestForm& operator=(brt::forms::RobotomyRequestForm const&) throw();

		std::string const&	getTarget( void ) const  throw();
		virtual void 		execute( void ) const throw();

	protected:
		std::string	_target;

};

#endif