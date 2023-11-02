/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 18:03:11 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:07:28 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 1 or name.empty() == true)
    {
        std::cout << "Invalid input" << std::endl;
        return (NULL);
    }
    Zombie *horde = new Zombie[N];
    if (horde == NULL)
    {
        std::cerr << "Memory fail" << std::endl;
        return (NULL);
    }
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}
