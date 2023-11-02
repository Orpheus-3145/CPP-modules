/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 18:50:55 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 12:39:32 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->no_conts = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
		this->contacts[i++] = Contact();
}

void PhoneBook::add_contact(Contact const &new_element)
{
	static int pos;

	if (pos == MAX_CONTACTS)
		pos = 0;
	this->contacts[pos++] = new_element;
	if (this->no_conts < MAX_CONTACTS)
		this->no_conts++;
}

static void trunc_over_ten(std::string to_print, std::string &truncated)
{
	truncated.assign(to_print, 0, 10);
	if (to_print.length() > 10)
		truncated[9] = '.';
}

void PhoneBook::display_contacts(void) const
{
	std::string buffer;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "ID";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < (int) this->no_conts; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		trunc_over_ten(this->contacts[i].get_first_name(), buffer);
		std::cout << "|" << std::setw(10) << std::right << buffer;
		trunc_over_ten(this->contacts[i].get_last_name(), buffer);
		std::cout << "|" << std::setw(10) << std::right << buffer;
		trunc_over_ten(this->contacts[i].get_nickname(), buffer);
		std::cout << "|" << std::setw(10) << std::right << buffer << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

int PhoneBook::get_contact_by_id(unsigned int index, Contact &id_cont) const 
{
	if (index < this->no_conts)
	{
		id_cont = this->contacts[index];
		return (0);
	}
	else
		return (1);
}

bool	PhoneBook::has_contacts() const
{
	return (this->no_conts != 0);
}