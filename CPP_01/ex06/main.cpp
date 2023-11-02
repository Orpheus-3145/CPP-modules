/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 16:42:58 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 16:51:24 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

t_logLevels	castInput(std::string str)
{
	static t_tuple functions[4] = {
        {"DEBUG", DEBUG},
        {"INFO", INFO},
        {"WARNING", WARNING},
        {"ERROR", ERROR}};

	for (int i = 0; i < 4; i++)
    {
        if (functions[i].strLogLvl.compare(str) == 0)
			return (functions[i].logLvl);
    }
	return (INVALID);
}

int main( int argc, char **argv )
{
	if (argc != 2)
		std::cout << "input not valid" << std::endl;
	else
	{
		Harl person = Harl(castInput(argv[1]));
		person.complain(DEBUG);
		person.complain(INFO);
		person.complain(WARNING);
		person.complain(ERROR);
	}
	return (0);
}