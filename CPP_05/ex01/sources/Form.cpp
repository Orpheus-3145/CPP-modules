/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 15:17:57 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 20:16:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

brt::Form::~Form( void ) throw()
{
	std::cout << "removed " << *this << std::endl;
}

brt::Form& brt::Form::operator=(brt::Form const& other) throw()
{
	if (this != &other)
		this->_signed = other.getSign();
	return (*this);
}

std::string const	brt::Form::getName( void ) const
{
	return (this->_name);
}

bool	brt::Form::getSign( void ) const
{
	return (this->_signed);
}

int	brt::Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int brt::Form::getGradeToExec( void ) const
{
	return (this->_gradeToExec);
}

void brt::Form::beSigned( brt::Bureaucrat& buro ) throw(brt::GradeTooLowException)
{
	std::string errorMessage = "";

	if (buro.getGrade() > this->_gradeToSign)
	{
		errorMessage.append(buro.toString());
		errorMessage.append(" is too low to sign ");
		errorMessage.append(this->toString());
		errorMessage.append(", level required: ");
		errorMessage.append(brt::getStrGrade(this->_gradeToSign));
		throw(errorMessage);
	}
	else
		this->_signed = true;
}

std::string 	brt::Form::toString ( void ) const throw()
{
	std::string verbal = "";
	verbal.append("form type: ");
	verbal.append(this->_name);
	if (this->_signed == false) 
		verbal.append(" not");
	verbal.append(" signed\ngrade required to sign: ");
	verbal.append(brt::getStrGrade(this->_gradeToSign));
	verbal.append("\ngrade required to execute: ");
	verbal.append(brt::getStrGrade(this->_gradeToExec));
	return (verbal);
}

std::ostream& operator<<(std::ostream& os, brt::Form const& toPrint)
{
	os << "form type " << toPrint.getName();
	if (toPrint.getSign() == false) 
		os << " not";
	os << " signed";
	return (os);
}