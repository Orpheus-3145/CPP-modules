/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 15:07:59 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 16:29:25 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::t_tuple Harl::functions[4] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
};

Harl::Harl( void )
{
    std::cout << "Harl appeared" << std::endl;
}

Harl::~Harl( void )
{
    std::cout << "Harl disappeared" << std::endl;
}

void Harl::complain( std::string input) const
{
    for (int i = 0; i < 4; i++)
    {
        if (Harl::functions[i].name.compare(input) == 0)
        {
            (this->*Harl::functions[i].fun_ptr)();
            return ;
        }
    }
    std::cout << "no valid input given" << std::endl;
}

void Harl::debug( void ) const
{
    std::cout << std::left << std::setw(17) << "[DEBUG LVL] " << DEBUG_MSG << std::endl;
}

void Harl::info( void ) const
{
    std::cout << std::left << std::setw(17) << "[INFO LVL] "  << INFO_MSG << std::endl;
}

void Harl::warning( void ) const
{
    std::cout << std::left << std::setw(17) << "[WARNING LVL] "  << WARNING_MSG << std::endl;
}

void Harl::error( void ) const
{
    std::cout << std::left << std::setw(17) << "[ERROR LVL] "  << ERROR_MSG << std::endl;
}
