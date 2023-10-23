/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:19:48 by fra           #+#    #+#                 */
/*   Updated: 2023/10/23 19:49:20 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) noexcept
{
	this->_maxItems = 0;
}

Span::Span( std::set<int>::size_type maxItems ) noexcept
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


void	Span::addNumber( int newNumber )
{
	if (this->_items.size() > this->_maxItems)
		throw(SpanException("Span is full already"));
	this->_items.insert(newNumber);
}

long		Span::shortestSpan( void ) const
{
	long	delta = *this->_items.rbegin();
	auto	currItem = (this->_items.begin());
	auto	prevItem = currItem++;

	if (this->_items.size() == 1)
		throw(SpanException("Span has only one element"));
	while (currItem != this->_items.end())
	{
		if ((*currItem - *prevItem) == 1)
			return (1);
		else if (delta > (*currItem - *prevItem))
			delta = *currItem - *prevItem;
		currItem++;
		prevItem++;
	}
	return (delta);
}

long		Span::longestSpan( void ) const
{
	if (this->_items.size() == 1)
		throw(SpanException("Span has only one element"));

	long minItem = *this->_items.begin();
	long maxItem = *this->_items.rbegin();
	if ((minItem * maxItem) > 0)
		return (std::abs(maxItem - minItem));
	else
		return (std::abs(maxItem) + std::abs(minItem));
}

void	Span::printSpan( void ) const noexcept
{
	for(auto item : this->_items)
		std::cout << item << std::endl;
}

std::set<int>::size_type		Span::getMaxItems( void ) const noexcept
{
	return (this->_maxItems);
}

void	Span::setMaxItems( std::set<int>::size_type newMax ) noexcept
{
	this->_maxItems = newMax;
}

std::set<int>	Span::getItems( void ) const noexcept
{
	return (this->_items);
}

void	Span::setItems( std::set<int> const& newItem ) noexcept
{
	this->_items = newItem;
}
