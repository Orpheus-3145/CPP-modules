/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 15:03:45 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 16:56:24 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# define DEBUG_MSG		"- I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define INFO_MSG		"- I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING_MSG	"- I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# define ERROR_MSG		"- This is unacceptable! I want to speak to the manager now."
# include <iostream>
# include <iomanip>

typedef enum s_logLevels
{
	INVALID,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
} t_logLevels;

typedef struct s_tuple
{
	std::string strLogLvl;
	t_logLevels	logLvl;
} t_tuple;

class Harl
{
	public:
		Harl( t_logLevels );
		~Harl( void );
		void complain( t_logLevels ) const;

	private:
		t_logLevels	_filter;

		void debug( void ) const;
		void info( void ) const;
		void warning( void ) const;
		void error( void ) const;
};

#endif