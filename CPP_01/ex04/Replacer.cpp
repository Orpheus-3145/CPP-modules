/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replacer.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 00:01:09 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 18:30:37 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

std::string	Replacer::_ext = ".replace";

Replacer::Replacer( void )
{
    this->_file_path = "";
    this->_old_str = "";
    this->_new_str = "";
    std::cout << "created (empty) instance" << std::endl;
}

Replacer::Replacer( std::string file_path, std::string old_str, std::string new_str )
{
    if (this->_validate_input(file_path, old_str, new_str) == false)
        throw (std::invalid_argument("Invalid input"));
    this->_file_path = file_path;
    this->_old_str = old_str;
    this->_new_str = new_str;
    std::cout << "created instance" << std::endl;
}

Replacer::~Replacer( void )
{
    std::cout << "closed instance" << std::endl;
}

int Replacer::replace( void ) const
{
    std::string     replace_file = this->_file_path + Replacer::_ext;
    std::string     next_line;
    std::fstream    r_file(this->_file_path.c_str(), std::ios::in);
    std::fstream    w_file(replace_file.c_str(), std::ios::out);

    if (r_file.is_open() == false)
    {
        std::cerr << "Error openening file: " << this->_file_path << std::endl;
        return (1);
    }
    if (w_file.is_open() == false)
    {
        std::cerr << "Error openening file: " << replace_file<< std::endl;
        r_file.close();
        return (1);
    }
    while (std::getline(r_file, next_line))
    {
        this->_replace_str(w_file, next_line);
        if (r_file.eof() == false)
            w_file << std::endl;
    }
    r_file.close();
    w_file.close();
    return (0);
}

bool Replacer::_validate_input( std::string file_path, std::string old_str, std::string new_str ) const
{
    std::fstream test;
    test.open(file_path.c_str());
    if (test.is_open() == false)
        return (false);
    test.close();
    if (old_str.empty() == true)
        return (false);
    else
        return (old_str.compare(new_str) != 0);
}

void    Replacer::_replace_str(std::fstream& out, std::string line) const
{
    size_t  last_pos = 0;
    size_t  pos = line.find(this->_old_str, last_pos);

    while (pos != std::string::npos)
    {
        out << line.substr(last_pos, pos - last_pos);
        out << this->_new_str;
        pos += this->_old_str.length();
        last_pos = pos;
        pos = line.find(this->_old_str, last_pos);

    } 
    out << line.substr(last_pos);
}
