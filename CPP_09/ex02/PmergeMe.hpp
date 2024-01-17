/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 20:47:53 by fra           #+#    #+#                 */
/*   Updated: 2024/01/17 13:26:42 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
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
		template <typename Cont> void	sort( Cont const& ) const noexcept ;
		intVect							toVector( void ) const noexcept ;
		intList							toList( void ) const noexcept ;
	
	private:
		std::string _inputString;
		int 		_jacobNumbers[21] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101};

		void				_splitAndSortVect( intVect const&, intVect&, intVect& ) const noexcept;
		void				_mergeInsertVect( intVect const&, intVect&, intVect& ) const noexcept ;
		void				_binaryInsertVect( intVect&, int, unsigned int ) const noexcept;
		void				_sortVectPairs(std::vector<std::pair<int, int>>&) const noexcept;
		void				_splitAndSortList( intList const&, intList&, intList& ) const noexcept;
		void				_mergeInsertList( intList&, intList& ) const noexcept ;
		void				_binaryInsertList( intList&, int, intList::iterator, intList::iterator ) const noexcept;
		void				_sortListPairs(std::list<std::pair<int, int>>&) const noexcept;
		void				_printSorted(size_t, int, const char*) const noexcept;
		template <typename Iterator>
		void				_advanceIter(Iterator&, Iterator, unsigned int) const noexcept;
};
