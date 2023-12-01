/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:19:48 by fra           #+#    #+#                 */
/*   Updated: 2023/12/01 13:54:29 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int maxItems ) noexcept
{
	this->_maxItems = maxItems;
}

Span::Span( Span const& other ) noexcept
{
	this->_maxItems = other.getMaxItems();
	this->_items = other.getItems();
}

Span::~Span( void ) noexcept
{
}

Span& Span::operator=(Span const& other ) noexcept
{
	if (this != &other)
	{
		this->_maxItems = other.getMaxItems();
		this->_items = other.getItems();
	}
	return (*this);
}

void	Span::addSingleNumber( int newNumber )
{
	if ((1 + this->_items.size()) > this->_maxItems)
		throw(SpanException("Span is full already"));
	this->_items.insert(newNumber);
}

size_t	Span::shortestSpan( void ) const
{
	size_t	delta;
	size_t 	minDelta = this->longestSpan();
	auto			currItem = (this->_items.begin());
	auto			prevItem = currItem++;

	if (this->_items.size() == 1)
		throw(SpanException("Span has only one element"));
	else if (this->_items.size() == 2)
		return (minDelta);
	while (currItem != this->_items.end())
	{
		delta = this->_norm(*currItem, *prevItem);
		if (delta == 0)
			break ;
		else if (minDelta > delta)
			minDelta = delta;
		currItem++;
		prevItem++;
	}
	return (delta);
}

size_t	Span::longestSpan( void ) const
{
	if (this->_items.size() == 1)
		throw(SpanException("Span has only one element"));

	return (this->_norm(*this->_items.begin(), *this->_items.rbegin()));
}

void	Span::printSpan( void ) const noexcept
{
	for(auto item : this->_items)
		std::cout << item << std::endl;
}

void	Span::setMaxItems( unsigned int newMax )
{
	if (newMax < this->_items.size())
		throw(SpanException("Span has already more items than the new size"));
	this->_maxItems = newMax;
}

void	Span::setItems( std::multiset<int> const& newItem )
{
	if (newItem.size() > this->_maxItems)
		throw(SpanException("New span has more items than the max size"));
	this->_items = newItem;
}

unsigned int		Span::getMaxItems( void ) const noexcept
{
	return (this->_maxItems);
}
	
std::multiset<int>	Span::getItems( void ) const noexcept
{
	return (this->_items);
}

size_t	Span::_norm( long n1, long n2 ) const noexcept
{
	if ((n1 * n2) > 0)
		return (std::abs(n1 - n2));
	else
		return (std::labs(n1) + std::labs(n2));
}