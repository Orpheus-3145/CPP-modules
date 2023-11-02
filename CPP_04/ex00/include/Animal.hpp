/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:04:19 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:05:49 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal 
{
	public:
		Animal( void );
		Animal( Animal const& );
		virtual ~Animal( void );
		Animal& 			operator=( Animal const& );
		void				setType( std::string& );
		std::string const&	getType( void ) const ;
		virtual void		makeSound( void ) const ;

	protected:
		std::string _type;
};

#endif