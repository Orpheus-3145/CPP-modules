/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 21:08:59 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:54:19 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    ScavTrap target("Jason");
    DiamondTrap test;
    test.whoAmI();
    test.printInfo();
    test.attack(target);
    return 0;
}
