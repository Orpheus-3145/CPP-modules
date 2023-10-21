/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 03:00:33 by fra           #+#    #+#                 */
/*   Updated: 2023/10/21 04:39:32 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>

class FindException : public std::exception
{
	public:
		FindException( std::string const& msg) throw() : std::exception() , _msg(msg) {}
		virtual const char* what() const throw() {return (this->_msg.c_str());}
		virtual ~FindException( void ) throw() {}
	
	private:
		std::string _msg;
};

template <typename T> int easyfind(T const&, int)
{
    throw(FindException("impossibile to run the generic function"));
}

template <>
int easyfind(std::vector<int> const& vect, int toFind)
{
    for(std::vector<int>::const_iterator st = vect.begin(); st != vect.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}

template <>
int easyfind(std::list<int> const& list, int toFind)
{
    for(std::list<int>::const_iterator st = list.begin(); st != list.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}

template <>
int easyfind(std::deque<int> const& deq, int toFind)
{
    for(std::deque<int>::const_iterator st = deq.begin(); st != deq.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}
