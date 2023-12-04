/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:51:06 by fra           #+#    #+#                 */
/*   Updated: 2023/12/04 20:40:12 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <set>
#include <stack>
#include <iterator>
#include <functional>

class RPN
{
	public:
		RPN( void ) {};
		~RPN( void ) {};

		static void	printResult( std::string ) ;

	private:
		static std::unordered_map<char, std::function<int(int, int)> > _ops;
	
		static bool	_checkInput( std::string ) ;
		static int	_findResult( std::string::iterator&, std::string::iterator, std::stack<int>& ) ;

		RPN( RPN const& ) : RPN() {};
		RPN& operator=( RPN const& ) {return (*this);};
};
