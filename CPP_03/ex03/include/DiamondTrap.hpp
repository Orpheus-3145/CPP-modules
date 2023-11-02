/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 01:16:29 by fra           #+#    #+#                 */
/*   Updated: 2023/10/08 01:27:30 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
	public:
		DiamondTrap( void ) ;
		DiamondTrap( std::string const& ) ;
		DiamondTrap( DiamondTrap const& ) ;
		~DiamondTrap( void ) ;
		void					whoAmI( void ) const ;
		virtual std::ostream&	present( std::ostream& ) const ;
		virtual void			attack( ClapTrap& other );
		virtual void			printInfo( void ) const ;

	private:
		std::string	_name;
};

#endif