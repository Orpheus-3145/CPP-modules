/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 21:08:59 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:46:04 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ClapTrap claptrap("Clap");
    ScavTrap scavtrap("Scav");
    FragTrap fragtrap("Frag");
    claptrap.attack(scavtrap);
    scavtrap.takeDamage(30);
    scavtrap.attack(fragtrap);
    fragtrap.takeDamage(25);
    claptrap.beRepaired(10);
    scavtrap.beRepaired(15);
    ClapTrap claptrap2 = scavtrap;
    ClapTrap claptrap3("New CL4P-TP");
    claptrap3 = fragtrap;
    scavtrap.guardGate();
    fragtrap.highFivesGuys();
    return 0;
}
