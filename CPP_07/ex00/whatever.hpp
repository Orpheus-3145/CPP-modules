/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:02:43 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 22:12:04 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T const& min(T const& a, T const& b)
{
	return ((a < b) ? a : b);
}

template <typename T> T const& max(T const& a, T const& b)
{
	return ((a > b) ? a : b);
}

#endif