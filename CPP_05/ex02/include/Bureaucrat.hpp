/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:35:19 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 00:34:45 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <sstream>

namespace brt
{
	class Bureaucrat;
	class AForm;
	class GenericException;
	class GradeTooHighException;
	class GradeTooLowException;
	int				gradeChecker( int );
	std::string		getStrGrade( int );
	const int 		_maxGrade = 1;
	const int 		_minGrade = 150;
}

class brt::GenericException : public std::exception
{
	public:
		GenericException( void ) throw() : std::exception() , _message(""){}
		GenericException( std::string const& msg ) throw() : std::exception() ,_message(msg) {}
		virtual ~GenericException() throw() { }
		virtual const char* what() const throw();

	protected:
		std::string const _message;
};

class brt::GradeTooHighException : public GenericException
{
	public:
		virtual const char* what() const throw();
};

class brt::GradeTooLowException : public brt::GenericException
{
	public:
		virtual const char* what() const throw();
};

class brt::Bureaucrat
{
	public:
		Bureaucrat( void ) throw() :
			_name("no_name") , _grade(brt::_minGrade) {};
		Bureaucrat( std::string const& name, int grade) 
			throw(brt::GradeTooHighException, brt::GradeTooLowException) :
			_name(name) , _grade(brt::gradeChecker(grade)) {}
		Bureaucrat( brt::Bureaucrat const& other) throw() :
			_name(other.getName()) , _grade(other.getGrade()) {};
		virtual ~Bureaucrat( void ) throw();
		brt::Bureaucrat& operator=( brt::Bureaucrat const& ) throw();

		std::string const&	getName( void ) const throw();
		int					getGrade( void ) const throw();
		void				incrementGrade( void ) throw(brt::GradeTooHighException);
		void				decrementGrade( void ) throw(brt::GradeTooLowException);
		void				signForm( brt::AForm& ) throw();
		void				executeForm( brt::AForm& ) throw();
		std::string  		toString ( void ) const throw();

	private:
		std::string const	_name;
		int 				_grade;

};

std::ostream& operator<<(std::ostream&, brt::Bureaucrat const& );

#endif