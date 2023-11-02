/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AbsAnimal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:04:19 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 01:47:50 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSANIMAL_HPP
#define ABSANIMAL_HPP
#include <iostream>
#include <string>
#include "Brain.hpp"

class AbsAnimal
{
public:
	AbsAnimal(void);
	AbsAnimal(AbsAnimal const &);
	virtual ~AbsAnimal(void);
	void setType(std::string &);
	std::string const &getType(void) const;

	void setBrain(Brain const &);
	Brain *getBrain(void) const;

	virtual void makeSound(void) const = 0;
	AbsAnimal &operator=(AbsAnimal const &);

protected:
	std::string _type;
	Brain *_brain;
};

#endif