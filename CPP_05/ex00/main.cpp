/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 01:12:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 15:06:26 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{	
	std::string name = "";
	int grade = 0;

	while (true)
	{
		std::cout << "Insert a name: ";
		std::cin  >> name;
		std::cout << "Insert a grade: ";
		std::cin  >> grade;
		try
		{
			Bureaucrat buro(name, grade);
			std::cout << "A new human lives! They're " << buro << std::endl;
			break ;
		}
		catch (GradeTooHighException const& error)
		{
			std::cout << "Grade too high (max is 1)" << std::endl;
		}
		catch (GradeTooLowException const& error)
		{
			std::cout << "Grade too low (min is 150)" << std::endl;
		}
	}
	return (0);
}