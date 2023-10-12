/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 01:12:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 20:17:05 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

int main( void )
{	
	std::string name = "Anselmo";
	int grade = 0;

	getGrade(grade);
	brt::Bureaucrat buro(name, grade);
	std::cout << "A new human lives! They're " << buro << std::endl;
	try
	{
		buro.incrementGrade();
		std:: cout << buro << " got a raise" << std::endl;
	}
	catch (brt::GradeTooHighException const& error)
	{
		std::cout << "grade of" << buro << " is the highest" << std::endl;
	}
	try
	{
		buro.incrementGrade();
		std:: cout << buro << " got a raise" << std::endl;
	}
	catch (brt::GradeTooHighException const& error)
	{
		std::cout << "grade of " << buro << " is the highest" << std::endl;
	}
	brt::Form document("contract", 123, 67);
	std::cout << "A new form exists:\n" << document.toString() << std::endl;
	buro.signForm(document);
	return (0);
}