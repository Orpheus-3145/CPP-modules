/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 20:47:53 by fra           #+#    #+#                 */
/*   Updated: 2023/10/31 18:51:09 by faru          ########   odam.nl         */
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
#include <chrono>

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
		template <typename Cont> void	sort( Cont const& ) const noexcept {}

		std::vector<int>	_toVector( void ) const noexcept ;
		std::list<int>		_toList( void ) const noexcept ;
		unsigned int		_getJacobIndex( int ) const noexcept ;
		void				_binaryInsert( std::vector<int>&, int, std::vector<int>::iterator, std::vector<int>::iterator ) const noexcept;
		void				_printSorted(size_t, int, const char*) const noexcept;

	private:
		std::string _inputString;
};
