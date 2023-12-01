/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:35:19 by fra           #+#    #+#                 */
/*   Updated: 2023/11/23 16:02:49 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>


class GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(std::string const msg) : 
			std::exception() , _msg(msg) {}
		virtual const char* what() const throw();
		virtual ~GradeTooHighException() throw() { }
	
	protected:
		const std::string _msg;
};

class GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(std::string const msg) : 
			std::exception() , _msg(msg) {}
		virtual const char* what() const throw();
		virtual ~GradeTooLowException() throw() {}
	
	protected:
		const std::string _msg;
};

class Bureaucrat
{
	public:
		Bureaucrat( void ) throw() :
			_name("no_name") , _grade(_minGrade) {};
		Bureaucrat( std::string const&, int ) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat( Bureaucrat const& other) throw() :
			_name(other.getName()) , _grade(other.getGrade()) {};
		virtual ~Bureaucrat( void ) throw();
		Bureaucrat& operator=( Bureaucrat const& ) throw();

		std::string const&	getName( void ) const throw();
		int					getGrade( void ) const throw();

		void	incrementGrade( void ) throw(GradeTooHighException);
		void	decrementGrade( void ) throw(GradeTooLowException);

	private:
		std::string const	_name;
		int 				_grade;

		static const int _maxGrade = 1;
		static const int _minGrade = 150;
};


std::ostream& operator<<(std::ostream&, Bureaucrat const& );

#endif