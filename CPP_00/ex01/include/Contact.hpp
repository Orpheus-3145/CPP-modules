/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 18:17:41 by fra           #+#    #+#                 */
/*   Updated: 2023/09/27 21:21:07 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string darkest_secret;

	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string darkest_secret);
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone() const;
		std::string get_darkest_secret() const;
		void 		print_info() const;
};

#endif