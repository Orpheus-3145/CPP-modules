/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 20:36:01 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:47:34 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>
# include <iomanip>

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( std::string const& );
		ClapTrap( ClapTrap const& );
		virtual ~ClapTrap( void );
		virtual void			attack( ClapTrap& );
		void					takeDamage(unsigned int amount );
		void					beRepaired(unsigned int amount );
		virtual std::ostream&	present( std::ostream& os ) const;
		std::string const&		getName( void ) const ;
		unsigned int			getHitPoints( void ) const ;
		unsigned int			getEnergyPoints( void ) const ;
		unsigned int			getAttackDamage( void ) const ;
		void					setName( std::string const& ) ;
		void					setHitPoints( unsigned int);
		void					setEnergyPoints( unsigned int);
		void					setAttackDamage( unsigned int);
		virtual void			printInfo( void ) const ;
		ClapTrap& 				operator=( ClapTrap const& );

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

std::ostream&	operator<<( std::ostream&, ClapTrap const& );

#endif