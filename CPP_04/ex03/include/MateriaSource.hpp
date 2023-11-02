/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 19:41:38 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 21:06:37 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource( void ) {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;		
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const& );
		MateriaSource& operator=( MateriaSource const& );
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
		AMateria const*		getMaterial( int ) const ;		

	private:
		static const int	_maxItems = 4;
		AMateria*			_inventory[_maxItems];	
};

#endif