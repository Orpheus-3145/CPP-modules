/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 16:12:02 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 16:28:57 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main( void )
{
	Base* test_inst = Base::generate();
	Base::identify(test_inst);
	Base::identify(*test_inst);
	delete test_inst;
	return (0);
}