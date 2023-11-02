/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:16:29 by faru          ########   odam.nl         */
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
		Cat( Cat const& other);
		~Cat( void );
		Cat& 			operator=( Cat const& );
		virtual void	makeSound ( void ) const ;
};

#endif