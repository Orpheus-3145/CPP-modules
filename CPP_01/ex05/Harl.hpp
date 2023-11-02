/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/29 15:03:45 by fra           #+#    #+#                 */
/*   Updated: 2023/10/19 16:29:32 by faru          ########   odam.nl         */
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

class Harl
{
	public:
		Harl( void );
		~Harl( void );
		void complain( std::string ) const;

	private:
		typedef struct s_tuple
		{
			std::string	name;
			void (Harl::*fun_ptr)( void) const;
		} t_tuple;

		static t_tuple	functions[4];

		void debug( void ) const;
		void info( void ) const;
		void warning( void ) const;
		void error( void ) const;
};

#endif