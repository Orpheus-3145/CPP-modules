/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:15:08 by fra           #+#    #+#                 */
/*   Updated: 2023/12/01 13:59:26 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
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
		Span( void ) noexcept {};
		Span( unsigned int maxItems ) noexcept;
		Span( Span const& ) noexcept;
		~Span( void ) noexcept;
		Span& operator=( Span const& ) noexcept;

		template <typename InputIterator>
		void			addMultipleNumbers( InputIterator start, InputIterator end )
		{
			if ((std::distance(start, end) + this->_items.size()) > this->_maxItems)	
				throw(SpanException("Too many elements to add"));
			this->_items.insert(start, end);
		};
		void				addSingleNumber( int ) ;
		size_t				shortestSpan( void ) const ;
		size_t				longestSpan( void ) const ;
		void				printSpan( void ) const noexcept;

		void				setMaxItems( unsigned int );
		void				setItems( std::multiset<int> const& );
		unsigned int		getMaxItems( void ) const noexcept;
		std::multiset<int>	getItems( void ) const noexcept;

	private:
		std::multiset<int>	_items;
		unsigned int		_maxItems = 0;

		size_t		_norm( long, long ) const noexcept;
};
