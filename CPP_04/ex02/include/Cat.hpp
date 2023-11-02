/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:08:40 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 15:41:33 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include <string>
# include "AbsAnimal.hpp"

class Cat : public AbsAnimal
{
	public:
		Cat( void );
		Cat( AbsAnimal const& );
		virtual ~Cat( void ) ;
		virtual void makeSound ( void ) const ;
};

#endif