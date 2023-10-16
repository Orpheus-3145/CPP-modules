/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:50:31 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 16:28:27 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	Base::generate(void)
{
	srand(time(0));
	int value = std::rand() % 3 + 1;
	switch (value)
	{
		case 1:
		{
			std::cout << "Istance of class A created" << std::endl;
			return (new A());
		}
		case 2:
		{
			std::cout << "Istance of class B created" << std::endl;
			return (new B());
		}
		case 3:
		{
			std::cout << "Istance of class C created" << std::endl;
			return (new C());
		}
	}
	return (NULL);
}

void		Base::identify(Base* ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "Pointer of class A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "Pointer of class B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "Pointer of class C" << std::endl;
}

void		Base::identify(Base& ptr)
{
	try
	{
		dynamic_cast<A&>(ptr);
		std::cout << "Reference of class A" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		dynamic_cast<B&>(ptr);
		std::cout << "Reference of class B" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		dynamic_cast<C&>(ptr);
		std::cout << "Reference of class C" << std::endl;
		return;
	}
	catch (...) {}
}
