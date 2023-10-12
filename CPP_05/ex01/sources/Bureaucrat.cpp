/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:56:38 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 20:06:13 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	brt::gradeChecker( int toCheck )
{
	if (toCheck < brt::_maxGrade)
		throw brt::GradeTooHighException("input too high");
	else if (toCheck > brt::_minGrade)
		throw brt::GradeTooLowException("input too low");
	else
		return (toCheck);
}

std::string		brt::getStrGrade( int grade )
{
	std::string strNumber;
    std::ostringstream ss;
    ss << grade ;
    strNumber = ss.str();
	return (strNumber);
}

brt::Bureaucrat::~Bureaucrat( void ) throw()
{
	std::cout << "removed " << *this << std::endl;
}

brt::Bureaucrat& brt::Bureaucrat::operator=( brt::Bureaucrat const& other ) throw()
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

std::string const&	brt::Bureaucrat::getName( void ) const throw()
{
	return (this->_name);
}

int		brt::Bureaucrat::getGrade( void ) const throw()
{
	return (this->_grade);
}

void	brt::Bureaucrat::incrementGrade( void ) throw(brt::GradeTooHighException)
{
	if (this->_grade == _maxGrade)
		throw (GradeTooHighException("increased too much"));
	else
		this->_grade--;
}

void	brt::Bureaucrat::decrementGrade( void ) throw(brt::GradeTooLowException)
{
	if (this->_grade == _maxGrade)
		throw (GradeTooLowException("decreased too much"));
	else
		this->_grade++;
}

void	brt::Bureaucrat::signForm( brt::Form& doc) throw()
{
	try
	{
		doc.beSigned(*this);
		std::cout << *this << " successfully signed " << doc << std::endl;
	}
	catch(GradeTooLowException const& err)
	{
		std::cout << *this << " couldn’t sign " << doc << " reason: " << err.what() <<std::endl;
	}
}

std::string 	brt::Bureaucrat::toString ( void ) const throw()
{
	std::string verbal = "";
	verbal.append(this->_name);
	verbal.append(", bureaucrat of grade ");
	verbal.append(getStrGrade(this->_grade));
	return (verbal);
}

const char* brt::GradeTooHighException::what( void ) const throw()
{
	return ("The grade of a bureaucrat was bigger than the maximum allowed");
}

const char* brt::GradeTooLowException::what( void ) const throw()
{
	return ("The grade of a bureaucrat was smaller than the minimum allowed");
}

std::ostream& operator<<(std::ostream& os, brt::Bureaucrat const& toPrint)
{
	os << toPrint.toString();
	return (os);
}
