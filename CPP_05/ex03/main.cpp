/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 01:12:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 20:46:28 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void getGrade(int& grade)
{
	while (true)
	{
		std::cout << "Insert a grade: ";
		std::cin  >> grade;
		try
		{
			brt::gradeChecker(grade);
			break ;
		}
		catch (brt::GradeTooHighException const& error)
		{
			std::cout << "Grade too high (max is 1)" << std::endl;
		}
		catch (brt::GradeTooLowException const& error)
		{
			std::cout << "Grade too low (min is 150)" << std::endl;
		}
	}
}

void promoteBuro(brt::Bureaucrat& buro)
{
	try
	{
		buro.incrementGrade();
		std:: cout << buro << " got promoted" << std::endl;
	}
	catch (brt::GradeTooHighException const& error)
	{
		std::cout << "grade of " << buro << " is already the highest" << std::endl;
	}
}

int main( void )
{	
	std::string name = "Anselmo";
	brt::Intern rookie;
	std::string forms[3] = {"presForm", "robotForm", "ShrubForm"};
	std::string targets[3] = {"Jericho", "GianAntonio", "C++"};
	brt::AForm *document;
	int grade = 0;

	getGrade(grade);
	brt::Bureaucrat buro(name, grade);
	std::cout << "A new human lives! They're " << buro << std::endl;
	promoteBuro(buro);
	promoteBuro(buro);
	std::cout << "We hired a new intern: they doesn't have a name" << std::endl;
	for (int i=0; i<3; i++)
	{
		document = rookie.makeForm(forms[i], targets[i]);
		std::cout << "A new form exists:\n" << document->toString() << std::endl;
		buro.signForm(*document);
		buro.executeForm(*document);
		delete document;
	}
	return (0);
}