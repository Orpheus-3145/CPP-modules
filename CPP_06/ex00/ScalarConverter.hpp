/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 02:16:14 by fra           #+#    #+#                 */
/*   Updated: 2023/10/15 19:57:05 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter &		operator=(ScalarConverter const &rhs);
		static void	convert( std::string const& );
};

#endif