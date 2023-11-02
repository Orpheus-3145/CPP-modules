/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 16:38:22 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 23:38:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {};
		virtual void				showInventory( void ) const = 0;
		virtual std::string const& 	getName() const = 0;
		virtual void 				equip( AMateria* ) = 0;
		virtual void 				unequip( int ) = 0;
		virtual void 				use( int , ICharacter& ) = 0;
};

class Character : public ICharacter
{
	public:
		Character( void );
		Character( std::string const& );
		Character( Character const& );
		virtual ~Character( void );

		virtual void				showInventory( void ) const;
		void						addEleToFloor( AMateria* );
		AMateria const* 			getMaterial( int ) const ;
		void						setName( std::string const& );
		virtual std::string const& 	getName( void ) const ;

		virtual void 				equip( AMateria* );
		virtual void 				unequip( int );
		virtual void 				use( int , ICharacter& );

		Character& 					operator=( Character const& );

	private:
		static const int	_maxItems = 4;
		static const int	_maxFloorItems = 1024;

		std::string			_name;
		AMateria*			_inventory[_maxItems];
		AMateria*			_floor[_maxFloorItems];
};

std::ostream& operator<<(std::ostream&, Character const& );

#endif