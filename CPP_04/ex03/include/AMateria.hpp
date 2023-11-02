/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 15:50:08 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 20:24:56 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "Character.hpp"

class ICharacter;

class AMateria
{
    public:
        AMateria( void );
        AMateria( std::string const& );
        AMateria( AMateria const& );
        virtual ~AMateria( void );

        std::string const & getType() const;
        void                setType( std::string const& );
    
        virtual AMateria*   clone() const = 0;
        virtual void        use( ICharacter& );

        AMateria& operator=( AMateria const& );

    protected:
        std::string _type;
};

std::ostream& operator<<(std::ostream&, AMateria const& );

#endif