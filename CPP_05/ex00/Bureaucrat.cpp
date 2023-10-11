/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:56:38 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 01:11:45 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const& name, int grade ) throw(GradeTooHighException, GradeTooLowException)
	: _name(name)
{
	if (grade < Bureaucrat::_maxGrade)
		throw GradeTooHighException("input too high");
	else if (grade > Bureaucrat::_minGrade)
		throw GradeTooLowException("input too low");
	else
		this->_grade = grade;
}


Bureaucrat::~Bureaucrat( void ) throw()
{
	std::cout << "removed " << *this << std::endl;
}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& other ) throw()
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}


std::string const&	Bureaucrat::getName( void ) const throw()
{
	return (this->_name);
}

int		Bureaucrat::getGrade( void ) const throw()
{
	return (this->_grade);
}


void	Bureaucrat::incrementGrade( void ) throw(GradeTooHighException)
{
	if (this->_grade == Bureaucrat::_maxGrade)
		throw (GradeTooHighException("increased too much"));
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade( void ) throw(GradeTooLowException)
{
	if (this->_grade == Bureaucrat::_maxGrade)
		throw (GradeTooLowException("decreased too much"));
	else
		this->_grade++;
}

const char* GradeTooHighException::what( void ) const throw()
{
	return ("The grade of a bureaucrat was bigger the maximum allowed");
}

const char* GradeTooLowException::what( void ) const throw()
{
	return ("The grade of a bureaucrat was smaller the minimum allowed");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& toPrint)
{
	os << toPrint.getName() << ", bureaucrat of grade " << toPrint.getGrade();
	return (os);
}
