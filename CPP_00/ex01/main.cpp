/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 19:06:22 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 14:27:29 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int		check_input(std::string index)
{
	char first_digit;

	first_digit = index[0];
	if ((first_digit >= '0') && (first_digit <= '7'))
	{
		if (index[1] == '\0')
			return (first_digit - '0');
	}
	return (-1);
}

int	search_entry(PhoneBook &pb)
{
	std::string str_id;
	int			id;
	Contact		to_print;

	pb.display_contacts();
	if (pb.has_contacts() == false)
	{
		std::cout << "Empty phonebook" << std::endl;
		return (0);
	}
	while (true)
	{
		std::cout << std::endl << "Select ID to search: ";
		std::cin >> str_id;
		if (std::cin.eof() == true)
			return (-1);
		id = check_input(str_id);
		if ((id != -1) && (pb.get_contact_by_id(id, to_print) == 0))
		{
			to_print.print_info();
			return (0);
		}
		std::cout << "Invalid id, try again" << std::endl;
	}
	return (0);
}

int	create_new_entry(PhoneBook &pb)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	darkest_secret;

	std::cout << "New contact:" << std::endl << "\tfirst name: ";
    std::getline(std::cin, first_name);
	std::cin >> first_name;
	if (std::cin.eof() == true)
		return (-1);
	std::cout << "\tlast name: ";
    std::getline(std::cin, last_name);
	std::cin >> last_name;
	if (std::cin.eof() == true)
		return (-1);
	std::cout << "\tnickname: ";
    std::getline(std::cin, nickname);
	std::cin >> nickname;
	if (std::cin.eof() == true)
		return (-1);
	std::cout << "\tphone: ";
    std::getline(std::cin, phone);
	std::cin >> phone;
	if (std::cin.eof() == true)
		return (-1);
	std::cout << "\tdarkest secret: ";
    std::getline(std::cin, darkest_secret);
	std::cin >> darkest_secret;
	if (std::cin.eof() == true)
		return (-1);
	pb.add_contact(Contact(first_name, last_name, nickname, phone, darkest_secret));
	return (0);
}

void	start_loop(PhoneBook &pb)
{
	std::string	input;

	std::cout << "Empty phonebook created" << std::endl;
	while (true)
	{
		std::cout << std::endl << "Select action between between ADD, SEARCH and EXIT" << std::endl;
		std::cin >> input;
		if (input == "ADD")
		{
			if (create_new_entry(pb) == -1)
				break;
		}
		else if (input == "SEARCH")
		{
			if (search_entry(pb) == -1)
				break ;
		}
		else if( (input == "EXIT") or (std::cin.eof() == true))
			break;
		else
			std::cout << "Wrong input, try again" << std::endl;
	}
}

int main()
{
	PhoneBook pb = PhoneBook();

	start_loop(pb);
	return (0);
}
