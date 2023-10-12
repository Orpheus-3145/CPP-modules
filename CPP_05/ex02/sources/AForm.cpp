/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 15:17:57 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 20:16:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* brt::FormNotSignedException::what( void ) const throw()
{
	return ("form not signed");
}

const char* brt::FormAlreadySignedException::what( void ) const throw()
{
	return ("form already signed");
}

brt::AForm::~AForm( void ) throw()
{
	std::cout << "removed " << *this << std::endl;
}

brt::AForm& brt::AForm::operator=(brt::AForm const& other) throw()
{
	if (this != &other)
		this->_signed = other.getSign();
	return (*this);
}

std::string const	brt::AForm::getName( void ) const
{
	return (this->_name);
}

bool	brt::AForm::getSign( void ) const
{
	return (this->_signed);
}

int	brt::AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int brt::AForm::getGradeToExec( void ) const
{
	return (this->_gradeToExec);
}

void brt::AForm::beSigned( brt::Bureaucrat& buro ) throw(brt::GradeTooLowException, brt::FormAlreadySignedException)
{
	if (buro.getGrade() > this->_gradeToSign)
		throw(GradeTooLowException());
	else if (this->_signed == true)
		throw(FormAlreadySignedException());
	else
		this->_signed = true;
}

void brt::AForm::beExecuted( brt::Bureaucrat& buro ) throw(brt::GradeTooLowException, brt::FormAlreadySignedException)
{
	if (buro.getGrade() > this->_gradeToSign)
		throw(GradeTooLowException());
	else if (this->_signed == false)
		throw(FormAlreadySignedException());
	else
		this->execute();
}

std::string 	brt::AForm::toString ( void ) const throw()
{
	std::string verbal = "";
	verbal.append("form type: ");
	verbal.append(this->_name);
	verbal.append(",");
	if (this->_signed == false) 
		verbal.append(" not");
	verbal.append(" signed\ngrade required to sign: ");
	verbal.append(brt::getStrGrade(this->_gradeToSign));
	verbal.append("\ngrade required to execute: ");
	verbal.append(brt::getStrGrade(this->_gradeToExec));
	return (verbal);
}

std::ostream& operator<<(std::ostream& os, brt::AForm const& toPrint)
{
	os << "form type " << toPrint.getName();
	return (os);
}