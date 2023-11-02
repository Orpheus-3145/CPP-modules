/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 16:42:58 by fra           #+#    #+#                 */
/*   Updated: 2023/09/30 01:47:44 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
    Harl person;

    person.complain("DEBUG");
    person.complain("INFO");
    person.complain("WARNING");
    person.complain("ERROR");
    return (0);
}