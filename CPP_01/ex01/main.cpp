/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 17:40:10 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 15:32:57 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    int     n_zombies = 10;
    Zombie  *zombies = zombieHorde(n_zombies, "Sigismondo");
    if (zombies == NULL)
        return (1);
    for (int i = 0; i < n_zombies; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}
