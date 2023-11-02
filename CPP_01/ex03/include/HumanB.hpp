/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 20:20:32 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:21:59 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB( void );
        void    attack ( void ) const;
        void    setWeapon( Weapon &new_weapon);

    private:
        std::string _name;
        Weapon*      _weapon;
};

#endif