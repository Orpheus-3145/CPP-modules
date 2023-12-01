/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyFind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 03:00:33 by fra           #+#    #+#                 */
/*   Updated: 2023/12/01 12:16:19 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <array>
#include <list>
#include <forward_list>
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

template <typename T> int easyFind(T const&, int)
{
    throw(FindException("input not a sequence container of integers"));
}

template <>
int easyFind(std::vector<int> const& vect, int toFind)
{
    for(auto st = vect.begin(); st != vect.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}

template<size_t N>
int easyFind(std::array<int, N> arr, int toFind)
{
    for(auto st = arr.begin(); st != arr.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}

template <>
int easyFind(std::list<int> const& list, int toFind)
{
    for(auto st = list.begin(); st != list.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}

template <>
int easyFind(std::forward_list<int> const& f_list, int toFind)
{
    for(auto st = f_list.begin(); st != f_list.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}

template <>
int easyFind(std::deque<int> const& deq, int toFind)
{
    for(auto st = deq.begin(); st != deq.end(); st++)
    {
        if (*st == toFind)
            return (*st);
    }
    throw(FindException("element not found"));
}
