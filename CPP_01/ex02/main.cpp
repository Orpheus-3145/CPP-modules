/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 19:00:10 by fra           #+#    #+#                 */
/*   Updated: 2023/09/28 19:08:13 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void )
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "string address: " << &str << std::endl;
    std::cout << "stringPTR address: " << &stringPTR << std::endl;
    std::cout << "stringREF address: " << &stringREF << std::endl;

    std::cout << "string value: " << str << std::endl;
    std::cout << "stringPTR value: " << *stringPTR << std::endl;
    std::cout << "stringREF value: " << stringREF << std::endl;
    return (0);
}