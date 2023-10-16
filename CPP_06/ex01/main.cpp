/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:35:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 15:44:01 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	Data *test = new Data;
	test->x = 1;
	test->y = 1;
	test->z = 1;
	if (test == Serializer::deserialize(Serializer::serialize(test)))
		std::cout << "ok" << std::endl;
	else
		std::cout << "not ok" << std::endl;
	delete test;
	return (0);
}