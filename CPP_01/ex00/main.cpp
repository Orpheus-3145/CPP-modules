/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 17:40:10 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 15:15:13 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    Zombie *new_zombie = newZombie("Giancarlo");
    if (new_zombie == NULL)
    {
        std::cerr << "Memory fail" << std::endl;
        return (1);
    }
    new_zombie->announce();
    delete new_zombie;

    randomChump("Percival");
    return (0);
}
