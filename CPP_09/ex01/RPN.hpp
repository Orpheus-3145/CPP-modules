/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:51:06 by fra           #+#    #+#                 */
/*   Updated: 2023/12/14 17:39:09 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <iterator>
#include <functional>
#include <unordered_map>

class RPNException : std::exception
{
	public:
		RPNException( std::string const& msg) noexcept : std::exception() , _msg(msg) {}
		virtual const char* what() const noexcept override {return (this->_msg.c_str());}
		virtual ~RPNException( void ) noexcept {}
	
	private:
		std::string _msg;
};

class RPN
{
	public:
		RPN( void ) {};
		~RPN( void ) {};

		static void	printResult( std::string ) ;

	private:
		static std::unordered_map<char, std::function<int(int, int)> > _ops;
	
		static void	_checkInput( std::string ) ;
		static int	_findResult( std::string::iterator&, std::string::iterator, std::stack<int>& ) ;

		RPN( RPN const& ) : RPN() {};
		RPN& operator=( RPN const& ) {return (*this);};
};
