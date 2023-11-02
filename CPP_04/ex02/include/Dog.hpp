/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 15:41:43 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include <string>
# include "AbsAnimal.hpp"

class Dog : public AbsAnimal
{
	public:
		Dog( void );
		Dog( AbsAnimal const& );
		virtual ~Dog( void ) ;
		virtual void makeSound ( void ) const ;
};

#endif