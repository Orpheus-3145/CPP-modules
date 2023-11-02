/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 19:17:07 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:13:12 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	public:
		Weapon( void );
		Weapon( std::string );
		~Weapon( void );
		std::string const& getType( void ) const;
		void setType(std::string const&);
	
	private:
		std::string _type;
};

#endif