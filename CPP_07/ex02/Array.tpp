/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 23:49:02 by fra           #+#    #+#                 */
/*   Updated: 2023/10/17 21:23:25 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void )
{
    this->_nItems = 0;
    this->_items = new T[0];
}

template <typename T>
Array<T>::Array( unsigned int n) throw(std::exception)
{
    this->_nItems = n;
    this->_items = new T[this->_nItems];
    if (this->_items == NULL)
        throw(std::exception());
}

template <typename T>
Array<T>::Array( Array<T>& other) throw(std::exception)
{
    this->_nItems = other.size();
    this->_items = new T[this->_nItems];
    if (this->_items == NULL)
        throw(std::exception());
    for (unsigned int i = 0; i < this->_nItems; i++)
        this->_items[i] = other[i];
}

template <typename T>
Array<T>::~Array( void ) throw()
{
    delete [] this->_items;
}

template <typename T>
Array<T>&	Array<T>::operator=( Array<T>& other ) throw(std::exception)
{
    unsigned int    newSize;
    T*              tmp;

    if (this != &other)
    {
        newSize = other.size();
        if (this->_nItems != newSize)
        {
            tmp = new T(newSize);
            if (tmp == NULL)
                throw(std::exception());
            for (unsigned int i = 0; i < newSize; i++)
                tmp[i] = other[i];
            delete [] this->_items;
        }
        else
        {
            tmp = this->_items;
            for (unsigned int i = 0; i < newSize; i++)
                tmp[i] = other[i];
        }
        this->_nItems = newSize;
        this->_items = tmp;
    }
    return (*this);
}

template <typename T>
T&		Array<T>::operator[]( int index ) throw(std::exception)
{
    if ((index < 0) or ((unsigned int) index >= this->_nItems))
        throw(std::exception());
    return (this->_items[index]);
}

template <typename T>
unsigned int	Array<T>::size( void ) const throw()
{
    return (this->_nItems);
}
