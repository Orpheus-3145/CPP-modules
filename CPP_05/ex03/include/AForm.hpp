/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 15:11:32 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 20:16:40 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

namespace brt
{
	class AForm;
	class FormNotSignedException;
	class FormAlreadySignedException;
}

class brt::FormNotSignedException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class brt::FormAlreadySignedException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class brt::AForm
{
	public:
		AForm( void ) throw() :
			_name("no_name") , 
			_signed(false) , 
			_gradeToSign(brt::_minGrade) , 
			_gradeToExec(brt::_minGrade) {}
		AForm( std::string const& name, int gradeSign, int gradeExec)
			throw(brt::GradeTooHighException, brt::GradeTooLowException) :
			_name(name) ,
			_signed(false) ,
			_gradeToSign(brt::gradeChecker(gradeSign)) ,
			_gradeToExec(brt::gradeChecker(gradeExec)) {}
		AForm( brt::AForm const& other) throw() :
			_name(other.getName()) ,
			_signed(other.getSign()) ,
			_gradeToSign(other.getGradeToSign()) ,
			_gradeToExec(other.getGradeToExec()) {}
		virtual ~AForm( void ) throw();
		brt::AForm& operator=(brt::AForm const&) throw();

		std::string const	getName( void ) const;
		bool				getSign( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExec( void ) const;

		void 				beSigned( brt::Bureaucrat& ) throw(brt::GradeTooLowException, brt::FormAlreadySignedException);
		void 				beExecuted( brt::Bureaucrat& buro ) throw(brt::GradeTooLowException, brt::FormAlreadySignedException);
		virtual void 		execute( void ) const throw(brt::GenericException) =0;

		std::string  		toString ( void ) const throw();


	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream& operator<<(std::ostream&, brt::AForm const& );

#endif