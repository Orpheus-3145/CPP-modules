/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 18:16:05 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 12:54:04 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define MAX_CONTACTS 8
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		unsigned int no_conts;
	
	public:
		PhoneBook();
		void	add_contact(Contact const &new_element);
		void	display_contacts() const ;
		int		get_contact_by_id(unsigned int index, Contact &id_cont) const ;
		bool	has_contacts() const ;
};

#endif