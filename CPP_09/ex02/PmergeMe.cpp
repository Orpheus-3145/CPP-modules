/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 21:21:03 by fra           #+#    #+#                 */
/*   Updated: 2023/11/01 23:53:05 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef std::pair<int,int> pair;

PmergeMe::PmergeMe( void ) noexcept :_inputString("") {}

PmergeMe::PmergeMe( std::string input )
{
	this->checkInput(input);
	this->_inputString = input;
}

PmergeMe::PmergeMe( PmergeMe const& other ) noexcept
{
	this->_inputString = other.getString();
}

PmergeMe& PmergeMe::operator=( PmergeMe const& other ) noexcept
{
	if (this != &other)
		this->_inputString = other.getString();
	return (*this);
}

std::string const&	PmergeMe::getString( void ) const noexcept 
{
	return (this->_inputString);
}

void	PmergeMe::setString( std::string const& newString ) noexcept
{
	this->_inputString = newString;
}

void		PmergeMe::checkInput( std::string input ) const 
{
	std::stringstream errMsg("");
	
	if (input.empty())
		throw(MergeException("empty string"));
	for (char digit : input)
	{
		if (!std::isdigit(digit) and (std::string("+ ").find(digit) == std::string::npos))
		{
			errMsg << " invalid character: < " << digit << " > in sequence: " << input ;
			throw(MergeException(errMsg.str()));
		}
	}	
}

template <>
void PmergeMe::sort<std::vector<int> >( std::vector<int> const& vectInput ) const noexcept
{
	
	unsigned int		nPairs = vectInput.size() / 2;
	std::vector<pair>	vectPairs;
	std::vector<int>	sorted;
	std::vector<int>	toSort;
	unsigned int		index;
	unsigned int		inserted;
	unsigned int		currJacobIndex;
	unsigned int		nextJacobIndex;

	// std::cout << "not sorted: ";
	// for (auto item : vectInput)
	// 	std::cout << item << "  ";
	// std::cout << std::endl;
	// auto start = std::chrono::high_resolution_clock::now();
	
	
	
	
	
	for (unsigned int i=0; i<nPairs; i++)
	{
		if (vectInput[i * 2] > vectInput[i * 2 + 1])
			vectPairs.push_back(pair({vectInput[i * 2], vectInput[i * 2 + 1]}));
		else
			vectPairs.push_back(pair({vectInput[i * 2 + 1], vectInput[i * 2]}));
	}
	std::sort(vectPairs.begin(), vectPairs.end(), [] (pair const& x, pair const& y) -> bool {return(x.first > y.first);} );
	for (int i=nPairs-1; i>=0; i--)
	{
		sorted.push_back(vectPairs[i].first);
		toSort.push_back(vectPairs[i].second);
	}
	index = 2;
	// for (auto item : sorted)
	// 	std::cout << item << "  ";
	// std::cout << "\n-------------------------------------------" << std::endl;
	currJacobIndex = PmergeMe::_getJacobIndex(index) - 1;
	sorted.insert(sorted.begin(), toSort[currJacobIndex]);
	// for (auto item : sorted)
	// 	std::cout << item << "  ";
	// std::cout << "\n-------------------------------------------" << std::endl;
	// std::cout << "is sorted: " << std::is_sorted(sorted.begin(), sorted.end()) << std::endl;
	inserted = 0;
	do
	{
		index++;
		nextJacobIndex = PmergeMe::_getJacobIndex(index) - 1;
		if (nextJacobIndex < nPairs)
		{
			PmergeMe::_binaryInsert(sorted, toSort[nextJacobIndex], sorted.begin(), sorted.begin() + inserted + nextJacobIndex);
			inserted++;
			// for (auto item : sorted)
			// 	std::cout << item << "  ";
			// std::cout << "\n-------------------------------------------" << std::endl;
			// if (std::is_sorted(sorted.begin(), sorted.end()) != 1)
			// 	break ;
		}
		for (int j=currJacobIndex + 1; j < std::min<int>(nextJacobIndex, nPairs); j++)
		{
			// std::cout << "inserting: " << toSort[j] << "\njacob index: " << currJacobIndex << "\nnextjacob index: " << nextJacobIndex<< "\ncurr index: " << j << std::endl;
			PmergeMe::_binaryInsert(sorted, toSort[j], sorted.begin(), sorted.begin() + inserted + nextJacobIndex);
			inserted++;
			// for (auto item : sorted)
			// 	std::cout << item << "  ";
			// std::cout << "\n-------------------------------------------" << std::endl;
			// if (std::is_sorted(sorted.begin(), sorted.end()) != 1)
			// 	break ;
		}
		// if (std::is_sorted(sorted.begin(), sorted.end()) != 1)
		// 	break ;
		currJacobIndex = nextJacobIndex;
		
	} while (currJacobIndex < nPairs - 1);
	if (vectInput.size() % 2)
		PmergeMe::_binaryInsert(sorted, vectInput.back(), sorted.begin(), sorted.end());
	
	
	
	
	
	
	
	
	// auto end = std::chrono::high_resolution_clock::now();
	// auto deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	// std::cout << "sorted: ";
	// for (auto item : sorted)
	// 	std::cout << item << "  ";
	// std::cout << std::endl;
	std::vector<int>::iterator sortEnd = sorted.begin();
	int cnt = 0;
	do
	{
		sortEnd = std::is_sorted_until(sortEnd, sorted.end());
		cnt++;
		if ((cnt == 1) and (sortEnd == sorted.end()))
		{
			std::cout << "is sorted! [" << std::is_sorted(sorted.begin(), sorted.end()) << "]" << std::endl;
			PmergeMe::_printSorted(vectInput.size(), 123, "vector");
		}
		else if (sortEnd != sorted.end())
		{
			std::cout << "fucking porcodio" << std::endl;
			for(auto i = sortEnd; i < sorted.end(); i++)
				std::cout << *i << "  ";
			std::cout << std::endl << std::endl << std::endl;
		}
	} while (sortEnd != sorted.end());
}

template <>
void PmergeMe::sort<std::list<int> >( std::list<int> const& listInput ) const noexcept
{
	(void)listInput;
}

std::vector<int>	PmergeMe::_toVector( void ) const noexcept 
{
	std::vector<int>	vect;
	std::string			currNumber = "";

	for (char digit : this->_inputString)
	{
		if (digit != ' ')
			currNumber += digit;
		else if (currNumber.empty() == false)
		{
			vect.push_back(std::stoi(currNumber));
			currNumber.clear();
		}
	}
	return (vect);
}

std::list<int>		PmergeMe::_toList( void ) const noexcept 
{
	std::list<int>	list;
	std::string		currNumber = "";

	for (char digit : this->_inputString)
	{
		if (digit != ' ')
			currNumber += digit;
		else if (currNumber.empty() == false)
		{
			list.push_back(std::stoi(currNumber));
			currNumber.clear();
		}
	}
	return (list);
}

unsigned int		PmergeMe::_getJacobIndex( int index ) const noexcept
{
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return ( _getJacobIndex(index - 1) + _getJacobIndex(index - 2) * 2);
}

void	PmergeMe::_binaryInsert(std::vector<int>& vect, int newItem, std::vector<int>::iterator start, std::vector<int>::iterator end) const noexcept
{
	std::vector<int>::iterator iter = std::upper_bound(start, end, newItem);
	vect.insert(iter, newItem);
}

void	PmergeMe::_printSorted(size_t nItems, int time, const char* contName) const noexcept
{
	std::cout << "Time to process a range of " << nItems << " elements with std::" << contName << ": " << time << " (microseconds)" << std::endl;
}