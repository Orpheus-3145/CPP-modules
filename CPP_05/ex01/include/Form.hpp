/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
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
	class Form;
}

class brt::Form
{
	public:
		Form( void ) throw() :
			_name("no_name") , 
			_signed(false) , 
			_gradeToSign(brt::_minGrade) , 
			_gradeToExec(brt::_minGrade) {}
		Form( std::string const& name, int gradeSign, int gradeExec)
			throw(brt::GradeTooHighException, brt::GradeTooLowException) :
			_name(name) ,
			_signed(false) ,
			_gradeToSign(brt::gradeChecker(gradeSign)) ,
			_gradeToExec(brt::gradeChecker(gradeExec)) {}
		Form( brt::Form const& other) throw() :
			_name(other.getName()) ,
			_signed(other.getSign()) ,
			_gradeToSign(other.getGradeToSign()) ,
			_gradeToExec(other.getGradeToExec()) {}
		virtual ~Form( void ) throw();
		brt::Form& operator=(brt::Form const&) throw();

		std::string const	getName( void ) const;
		bool				getSign( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExec( void ) const;

		void beSigned( brt::Bureaucrat& ) throw(brt::GradeTooLowException);

		std::string  		toString ( void ) const throw();

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream& operator<<(std::ostream&, brt::Form const& );

#endif