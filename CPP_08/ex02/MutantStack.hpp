/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 20:15:16 by fra           #+#    #+#                 */
/*   Updated: 2023/12/01 14:23:03 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>
#include <iterator>
#include <stack>

template <typename T, class U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
	public:
		typedef typename U::iterator					iterator;
		typedef typename U::const_iterator				const_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typename U::iterator begin( void ) noexcept {return (this->c.begin());}
		typename U::iterator end( void ) noexcept  {return (this->c.end());}
		typename U::iterator rbegin( void ) noexcept  {return (this->c.rbegin());}
		typename U::iterator rend( void ) noexcept  {return (this->c.rend());}
		typename U::const_iterator cbegin( void ) const noexcept  {return (this->c.cbegin());}
		typename U::const_iterator cend( void ) const noexcept  {return (this->c.cend());}
		typename U::const_iterator crbegin( void ) noexcept  {return (this->c.crbegin)();}
		typename U::const_iterator crend( void ) noexcept  {return (this->c.crend());}
};
