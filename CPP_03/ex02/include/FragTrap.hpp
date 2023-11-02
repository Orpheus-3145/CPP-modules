/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 22:08:21 by fra           #+#    #+#                 */
/*   Updated: 2023/10/06 03:28:18 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const& other );
		virtual ~FragTrap( void );
		virtual void			attack( ClapTrap& other );
		void 					highFivesGuys() const ;
		virtual std::ostream&	present( std::ostream& os ) const ;
};

#endif