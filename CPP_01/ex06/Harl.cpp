/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 15:07:59 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 16:58:55 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( t_logLevels level )
{
    this->_filter = level;
    std::cout << "Harl appeared" << std::endl;
}

Harl::~Harl( void )
{
    std::cout << "Harl disappeared" << std::endl;
}

void Harl::complain( t_logLevels input) const
{
    if (this->_filter == INVALID)
        std::cout << "Filter not valid, no message will be filtered" << std::endl;
    switch (input)
    {
        case DEBUG:
            if (this->_filter <= input) this->debug();
            break ;
        case INFO:
            if (this->_filter <= input) this->info();
            break ;
        case WARNING:
            if (this->_filter <= input) this->warning();
            break ;
        case ERROR:
            if (this->_filter <= input) this->error();
            break ;
        default:
            std::cout << "invalid input" <<std::endl;
            break;
    }
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
