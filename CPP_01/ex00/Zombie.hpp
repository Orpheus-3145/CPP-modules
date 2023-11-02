/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 16:33:27 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 15:11:19 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    public:
        Zombie( void );
        Zombie( std::string name );
        ~Zombie( void);
        void announce( void ) const;

    private:
        std::string _name;
};

Zombie* newZombie( std::string name );

void    randomChump( std::string name );

#endif
