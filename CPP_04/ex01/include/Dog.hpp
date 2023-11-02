/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:11:05 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog( void );
		Dog( Animal const& );
		virtual ~Dog( void ) ;
		virtual void makeSound ( void ) const ;
};

#endif