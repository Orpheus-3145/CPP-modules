/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:24:56 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 15:42:59 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AbsAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{	
	AbsAnimal test = AbsAnimal();
	// AbsAnimal** catsAndDogs = new AbsAnimal*[20];
	// std::cout << "creating animals" << std::endl << std::endl;
	// for (int i = 0; i < 20; i++)
	// {
	// 	if ((i % 2) == 0)
	// 		catsAndDogs[i] = new Cat();
	// 	else
	// 		catsAndDogs[i] = new Dog();
	// 	std::cout << std::endl;
	// }
	// std::cout << "they can speak!" << std::endl;
	// for (int i = 0; i < 20; i++)
	// 	catsAndDogs[i]->makeSound();
	// std::cout << std::endl << "time is over" << std::endl;
	// for (int i = 0; i < 20; i++)
	// 	delete catsAndDogs[i];
	// delete [] catsAndDogs;
	// std::cout << "removed array catsAndDogs" << std::endl;
	return (0);
}