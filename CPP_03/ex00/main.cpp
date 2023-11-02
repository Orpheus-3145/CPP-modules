/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 21:08:59 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:25:49 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap claptrap1("Giampiero");
    ClapTrap claptrap2("Marco Antonio");

    claptrap1.beRepaired(3);
    claptrap1.beRepaired(6);
    claptrap1.beRepaired(7);
    claptrap1.beRepaired(8);

    for( int i = 0; i < 10; i++)
        claptrap1.attack(claptrap2);
    // ClapTrap claptrap3("Gilberto");
    // ClapTrap claptrap4("Anastasia");

    // claptrap3.attack(claptrap4);
    // claptrap4.takeDamage(15);

    // claptrap1.beRepaired(10);
    // claptrap2.beRepaired(5);

    // ClapTrap claptrap5("Teodora");

    // claptrap5.attack(claptrap1);
    // claptrap1.takeDamage(25);

    // ClapTrap claptrap6 = claptrap2;
    // claptrap2.attack(claptrap6);
    // claptrap6.takeDamage(30);

    // claptrap1.attack(claptrap4);
    // claptrap4.takeDamage(10);

    // claptrap5.attack(claptrap3);
    // claptrap3.takeDamage(12);

    // claptrap6.beRepaired(8);
    // claptrap4.beRepaired(7);

    // ClapTrap claptrap7("Adelasio");
    // claptrap7.attack(claptrap1);
    // claptrap1.takeDamage(17);

    // ClapTrap claptrap8 = claptrap4;
    // claptrap8.attack(claptrap3);
    // claptrap3.takeDamage(22);

    // claptrap7.beRepaired(15);
    // claptrap8.beRepaired(12);

    // ClapTrap claptrap9("Carmen");
    // claptrap9.attack(claptrap5);
    // claptrap5.takeDamage(18);

    // ClapTrap claptrap10("Attasio");
    // claptrap10.attack(claptrap6);
    // claptrap6.takeDamage(14);

    // ClapTrap claptrap11("Kara");
    // claptrap11.attack(claptrap7);
    // claptrap7.takeDamage(21);
    return 0;
}
