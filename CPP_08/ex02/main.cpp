/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 20:41:56 by fra           #+#    #+#                 */
/*   Updated: 2023/12/01 14:21:08 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <limits>
#include <list>
#include <iostream>
#include "MutantStack.hpp"

int main( void )
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size " <<  mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "the following output should be the same\n";
    std::list<int> checkList;
    checkList.push_back(5);
    checkList.push_back(17);
    std::cout << "top " << checkList.back() << std::endl;
    checkList.pop_back();
    std::cout << "size " <<  checkList.size() << std::endl;
    checkList.push_back(3);
    checkList.push_back(5);
    checkList.push_back(737);
    checkList.push_back(0);
    std::list<int>::iterator l_it = checkList.begin();
    std::list<int>::iterator l_ite = checkList.end();
    ++l_it;
    --l_it;
    while (l_it != l_ite)
    {
        std::cout << *l_it << std::endl;
        ++l_it;
    }
    return (0);
}