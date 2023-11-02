/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 18:28:36 by fra           #+#    #+#                 */
/*   Updated: 2023/09/27 22:22:32 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    this->first_name = "empty";
    this->last_name = "empty";
    this->nickname = "empty";
    this->phone = "empty";
    this->darkest_secret = "empty";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone = phone;
    this->darkest_secret = darkest_secret;
}

void Contact::print_info() const
{
    std::cout << "Contact info" << std::endl;
    std::cout << "\tfirst name: " << this->first_name << std::endl;
    std::cout << "\tlast name: " << this->last_name << std::endl;
    std::cout << "\tnickname: " << this->nickname << std::endl;
    std::cout << "\tphone: " << this->phone << std::endl;
    std::cout << "\tdarkest secret: " << this->darkest_secret << std::endl;
}

std::string Contact::get_first_name() const
{
    return (this->first_name);
}

std::string Contact::get_last_name() const
{
    return (this->last_name);
}

std::string Contact::get_nickname() const
{
    return (this->nickname);
}

std::string Contact::get_phone() const
{
    return (this->phone);
}

std::string Contact::get_darkest_secret() const
{
    return (this->darkest_secret);
}
