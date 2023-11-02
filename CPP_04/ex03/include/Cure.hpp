/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 16:33:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 19:40:46 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( std::string const& );
		Cure( Cure const& );
		virtual ~Cure( void );

        virtual AMateria*   clone() const ;
        virtual void        use( ICharacter& );
};

#endif