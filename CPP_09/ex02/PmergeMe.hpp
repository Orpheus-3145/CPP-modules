/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 20:47:53 by fra           #+#    #+#                 */
/*   Updated: 2023/11/02 22:10:22 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <string>
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
	typedef std::vector<int>	intVect;
	typedef std::list<int>		intList;
	
	public:
		PmergeMe( void ) noexcept {};
		PmergeMe( std::string );
		PmergeMe( PmergeMe const& ) noexcept;
		~PmergeMe( void ) noexcept {}
		PmergeMe& operator=( PmergeMe const& ) noexcept;

		std::string const&	getString( void ) const noexcept ;
		void				setString( std::string const& ) ;
		
		void							checkInput( std::string ) const ;
		template <typename Cont> void	sort( Cont const& ) const noexcept {}
		intVect							toVector( void ) const noexcept ;
		intList							toList( void ) const noexcept ;
	
		void				_splitAndSortVect( intVect const&, intVect&, intVect& ) const noexcept;
		void				_mergeInsertVect( intVect const&, intVect&, intVect& ) const noexcept ;
		void				_binaryInsertVect( intVect&, int, unsigned int ) const noexcept;
		void				_binaryInsertList( intList&, int, intList::iterator, intList::iterator ) const noexcept;
		void				_splitAndSortList( intList const&, intList&, intList& ) const noexcept;
		void				_mergeInsertList( intList const&, intList&, intList& ) const noexcept ;
		unsigned int		_getJacobIndex( int ) const noexcept ;
		void				_printSorted(size_t, int, const char*) const noexcept;
		template <typename Iterator>
		void				_advanceIter(Iterator&, Iterator, unsigned int) const noexcept;

	private:
		std::string _inputString;
};
