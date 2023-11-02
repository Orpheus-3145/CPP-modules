/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:16:32 by faru          ########   odam.nl         */
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
		Dog( Dog const& other);
		~Dog( void );
		Dog& 			operator=( Dog const& );
		virtual void	makeSound ( void ) const ;
};

#endif