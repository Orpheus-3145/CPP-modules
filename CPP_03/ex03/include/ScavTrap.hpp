/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 22:08:21 by fra           #+#    #+#                 */
/*   Updated: 2023/10/07 02:09:46 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const& other );
		virtual ~ScavTrap( void );
		virtual void			attack( ClapTrap& other );
		virtual std::ostream&	present( std::ostream& os ) const ;
		void 					guardGate() const ;
};

#endif