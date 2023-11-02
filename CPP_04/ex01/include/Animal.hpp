/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:04:19 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:08:25 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal 
{
	public:
		Animal( void );
		Animal( Animal const& );
		virtual ~Animal( void );
		void				setType( std::string& );
		std::string const&	getType( void ) const ;

		void				setBrain( Brain const& );
		Brain*				getBrain( void ) const ;

		virtual void		makeSound( void ) const ;
		Animal& 			operator=( Animal const& );

	protected:
		std::string 	_type;
		Brain*			_brain;
};

#endif