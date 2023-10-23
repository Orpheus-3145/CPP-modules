/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:15:08 by fra           #+#    #+#                 */
/*   Updated: 2023/10/23 21:57:01 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <set>

class SpanException : public std::exception
{
	public:
		SpanException( std::string const& msg) throw() : std::exception() , _msg(msg) {}
		virtual const char* what() const throw() {return (this->_msg.c_str());}
		virtual ~SpanException( void ) throw() {}
	
	private:
		std::string _msg;
};

class Span
{
	public:
		Span( void ) noexcept;
		Span( std::set<int>::size_type maxItems ) noexcept;
		Span( Span const& ) noexcept;
		~Span( void ) noexcept;
		Span& operator=( Span const& ) noexcept;

		void	addNumber( int ) ;
		template <class ClassIterator>
		void	addMultipleNumbers( ClassIterator start, ClassIterator end ) {
			this->_items.insert(start, end);
		}
		long	shortestSpan( void ) const ;
		long	longestSpan( void ) const ;
		void	printSpan( void ) const noexcept;

		std::set<int>::size_type	getMaxItems( void ) const noexcept;
		void						setMaxItems( std::set<int>::size_type ) noexcept;
		std::set<int>				getItems( void ) const noexcept;
		void						setItems( std::set<int> const& ) noexcept;

	private:
		std::set<int>				_items;
		std::set<int>::size_type	_maxItems;
};
