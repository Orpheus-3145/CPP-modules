/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:47:42 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 16:20:52 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base( void ) {}
		static Base*	generate( void );
		static void		identify( Base* );
		static void		identify( Base& );
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif