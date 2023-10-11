/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 01:12:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/12 01:15:24 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat buro("Adelasio", 111);
	std::cout << " a new human lives! They're " << buro << std::endl;
	return (0);
}