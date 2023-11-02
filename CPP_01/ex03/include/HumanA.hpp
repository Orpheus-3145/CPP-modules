/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 20:09:12 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:22:15 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string, Weapon&);
		~HumanA( void );
		void	attack ( void ) const;

	private:
		std::string     _name;
		Weapon&         _weapon;
};

#endif