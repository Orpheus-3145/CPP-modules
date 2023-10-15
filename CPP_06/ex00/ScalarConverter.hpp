/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 02:16:14 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 01:21:08 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>	// std::cout, std::endl
# include <cstdlib>		// std::atoi, std::strtof, std::strtod
# include <limits>		// std::numeric_limits
# include <cmath>		// std::isnan, std::isinf

class ScalarConverter
{
	public:
		ScalarConverter( void ) {};
		ScalarConverter( ScalarConverter const& ) {};
		~ScalarConverter( void ) {};
		ScalarConverter&	operator=(ScalarConverter const& ) {return (*this);};
		static void			convert( std::string const& );
};

#endif