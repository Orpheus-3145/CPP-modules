/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 16:33:27 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:07:12 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	public:
		Zombie( void );
		Zombie( std::string name);
		~Zombie( void );
		void	announce( void ) const ;
		void	setName( std::string& );

	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
