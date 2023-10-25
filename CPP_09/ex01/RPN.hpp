/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:51:06 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 19:32:19 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <functional>

class RPN
{
	public:
		RPN( void );
		RPN( RPN const& ) : RPN() {}
		~RPN( void ) {}	
		RPN& operator=( RPN const& );

		void	printResult( std::string ) ;

		int		_findResult( std::string::iterator, std::string::iterator ) ;
		bool	_checkInput( std::string ) const ;

	private:
		std::unordered_map<char, std::function<int(int, int)> > _ops;
};
