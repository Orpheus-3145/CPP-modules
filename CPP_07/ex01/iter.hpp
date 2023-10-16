/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 22:02:43 by fra           #+#    #+#                 */
/*   Updated: 2023/10/16 23:41:06 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T> void funzia(T& toModify)
{
	toModify += 1;
}

template <typename T> void iter(T arr[], int size, void (*funPtr)(T&))
{
	if (funPtr == NULL)
		return ;
	for (int i = 0; i < size; i++)
		funPtr(arr[i]);
}

#endif