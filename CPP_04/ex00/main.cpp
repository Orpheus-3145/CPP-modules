/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:24:56 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 19:23:58 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	const WrongAnimal* w_i = new WrongCat();
	WrongCat tmp = WrongAnimal();
	std::cout << tmp.getType() << std::endl;
	tmp.makeSound();
	delete w_i;
	return 0;
}