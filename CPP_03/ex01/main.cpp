/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 21:08:59 by fra           #+#    #+#                 */
/*   Updated: 2023/10/06 02:59:03 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap claptrap1("R2D2");
    ScavTrap claptrap2("C3PO");
    claptrap1.attack(claptrap2);
    claptrap2.takeDamage(20);
    ScavTrap scavtrap2("Bender");
    ScavTrap scavtrap1(scavtrap2);
    scavtrap1.attack(scavtrap2);
    scavtrap2.takeDamage(15);
    claptrap1.attack(scavtrap1);
    scavtrap1.takeDamage(25);
    scavtrap1.guardGate();
    ClapTrap claptrap3 = scavtrap2;
    ClapTrap claptrap4("HK42");
    claptrap4 = scavtrap1;
    claptrap4.attack(claptrap2);
    claptrap2.beRepaired(10);
    claptrap1.beRepaired(5);
    ScavTrap scavtrap3("Data");
    ScavTrap scavtrap4("Walle");
    scavtrap3.attack(scavtrap4);
    scavtrap4.takeDamage(30);
    claptrap1.attack(scavtrap3);
    scavtrap3.takeDamage(22);
    scavtrap4.beRepaired(8);
    claptrap3.beRepaired(7);
    return 0;
}