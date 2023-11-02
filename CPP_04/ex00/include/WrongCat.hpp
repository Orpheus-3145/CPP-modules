/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/09 15:27:42 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongAnimal const& );
		~WrongCat( void ) ;
		virtual void makeSound ( void ) const ;
};

#endif