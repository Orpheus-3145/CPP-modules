/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 16:07:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 19:40:49 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( std::string const& );
		Ice( Ice const& );
		virtual ~Ice( void );

        virtual AMateria*   clone() const ;
        virtual void        use( ICharacter& );
};

#endif