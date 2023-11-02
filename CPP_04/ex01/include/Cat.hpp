/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:11:09 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include <string>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat( void );
		Cat( Animal const& );
		virtual ~Cat( void ) ;
		virtual void makeSound ( void ) const ;
};

#endif