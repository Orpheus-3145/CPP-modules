/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 22:08:21 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 18:29:08 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const& other );
		virtual ~ScavTrap( void );
		virtual void			attack( ClapTrap& other );
		void 					guardGate() const ;
		virtual std::ostream&	present( std::ostream& os ) const ;
};

#endif