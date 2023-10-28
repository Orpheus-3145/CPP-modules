/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 20:47:53 by fra           #+#    #+#                 */
/*   Updated: 2023/10/28 03:11:58 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <iomanip>
#include <iterator>

class MergeException : std::exception
{
	public:
		MergeException( std::string const& msg) noexcept : std::exception() , _msg(msg) {}
		virtual const char* what() const noexcept override {return (this->_msg.c_str());}
		virtual ~MergeException( void ) noexcept {}
	
	private:
		std::string _msg;
};

class PmergeMe
{
	public:
		PmergeMe( void ) noexcept ;
		PmergeMe( std::string );
		PmergeMe( PmergeMe const& ) noexcept;
		~PmergeMe( void ) noexcept {}
		PmergeMe& operator=( PmergeMe const& ) noexcept;

		std::string const&	getString( void ) const noexcept ;
		void				setString( std::string const& ) noexcept ;
		
		void							checkInput( std::string ) const ;
		template <typename Cont> void	sortInput( void ) const noexcept {}

		std::vector<int>	_toVector( void ) const noexcept ;
		std::list<int>		_toList( void ) const noexcept ;
		int					_generateJacobsthal( int ) const noexcept ;
		void				_binaryInsert( std::vector<int>&, int ) const noexcept;

	private:
		std::string _inputString;
};
