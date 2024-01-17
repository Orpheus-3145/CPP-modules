/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 21:21:03 by fra           #+#    #+#                 */
/*   Updated: 2024/01/17 17:08:09 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef std::pair<int,int>	pair;
typedef std::vector<int>	intVect;
typedef std::list<int>		intList;

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

void	PmergeMe::setString( std::string const& newString )
{
	this->checkInput(newString);
	this->_inputString = newString;
}

void		PmergeMe::checkInput( std::string input ) const 
{
	std::stringstream	errorStream("");
	std::string			currNumber;
	long				number;

	for (char digit : input)
	{
		if ((digit == ' ') or 
			(digit == '\n') or
			(digit == '\t'))
		{
			if (currNumber.empty() == false)
			{
				try {
					number = std::stol(currNumber);
				}
				catch(const std::invalid_argument& e) {
					throw(MergeException(std::string("not valid: ").append(currNumber)));
				}
				if ((number < INT32_MIN) or (number > INT32_MAX))
					throw(MergeException(std::string("overflow or underflow: ").append(currNumber)));
				currNumber.clear();
			}
		}
		else if ((std::isdigit(digit) == true) || (digit == '+'))
			currNumber += digit;
		else if (digit == '-')
			throw(MergeException("numbers most be 0 or positive"));
		else
		{
			errorStream << " invalid character: <" << digit << "> in sequence";
			throw(MergeException(errorStream.str()));
		}
	}
	if (currNumber.empty() == false)
	{
		try {
			number = std::stol(currNumber);
		}
		catch(const std::invalid_argument& e) {
			throw(MergeException(std::string("not valid: ").append(currNumber)));
		}
		if ((number < INT32_MIN) or (number > INT32_MAX))
			throw(MergeException(std::string("overflow or underflow: ").append(currNumber)));
	}
}

template <>
void PmergeMe::sort<intVect >( intVect const& vectInput ) const noexcept
{
	intVect	sorted;
	intVect	toSort;

	if (vectInput.size() <= 1)
	{
		std::cout << "input is a singleton or empty" << std::endl;
		return ;
	}
	auto start = std::chrono::high_resolution_clock::now();
	this->_splitAndSortVect(vectInput, sorted, toSort);
	this->_mergeInsertVect(vectInput, sorted, toSort);
	auto end = std::chrono::high_resolution_clock::now();
	auto deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "is sorted: ";
	(std::is_sorted(sorted.begin(), sorted.end()) == 1) ? std::cout << "true" : std::cout << "false";
	PmergeMe::_printSorted(sorted.size(), deltaTime, "vector");
}

template <>
void PmergeMe::sort<intList >( intList const& listInput ) const noexcept
{
	intList	sorted;
	intList	toSort;

	if (listInput.size() <= 1)
	{
		std::cout << "input is a singleton or empty" << std::endl;
		return ;
	}
	auto start = std::chrono::high_resolution_clock::now();
	this->_splitAndSortList(listInput, sorted, toSort);
	this->_mergeInsertList(sorted, toSort);
	auto end = std::chrono::high_resolution_clock::now();
	auto deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "is sorted: ";
	(std::is_sorted(sorted.begin(), sorted.end()) == 1) ? std::cout << "true" : std::cout << "false";
	PmergeMe::_printSorted(sorted.size(), deltaTime, "list");
}

intVect	PmergeMe::toVector( void ) const noexcept 
{
	intVect				vect;
    int					number;
    std::stringstream	ss(this->_inputString);

    while (ss >> number)
		vect.push_back(number);
	return (vect);
}

intList	PmergeMe::toList( void ) const noexcept 
{
	intList				list;
    int					number;
    std::stringstream	ss(this->_inputString);

    while (ss >> number)
		list.push_back(number);
	return (list);
}

void	PmergeMe::_splitAndSortVect( intVect const& vectInput, intVect& sorted, intVect& toSort ) const noexcept
{
	unsigned int		nPairs = vectInput.size() / 2;
	std::vector<pair>	vectPairs;

	for (unsigned int i=0; i<nPairs; i++)
	{
		if (vectInput[i * 2] > vectInput[i * 2 + 1])
			vectPairs.push_back(pair({vectInput[i * 2], vectInput[i * 2 + 1]}));
		else
			vectPairs.push_back(pair({vectInput[i * 2 + 1], vectInput[i * 2]}));
	}
	_sortVectPairs(vectPairs);
	for (int i=nPairs-1; i>=0; i--)
	{
		sorted.push_back(vectPairs[i].first);
		toSort.push_back(vectPairs[i].second);
	}
}

void	PmergeMe::_mergeInsertVect( intVect const& vectInput, intVect& sorted, intVect& toSort ) const noexcept
{
	unsigned int	nPairs = vectInput.size() / 2;
	unsigned int	index = 1;
	unsigned int	inserted = 0;
	unsigned int	currJacobIndex = 0;
	unsigned int	nextJacobIndex = 0;

	if (toSort.empty() == true)
		return;
	sorted.insert(sorted.begin(), toSort[currJacobIndex]);
	inserted++;
	do
	{
		nextJacobIndex = this->_jacobNumbers[index] - 1;
		if (nextJacobIndex < nPairs)
			PmergeMe::_binaryInsertVect(sorted, toSort[nextJacobIndex], inserted++ + nextJacobIndex);
		for (int j=currJacobIndex + 1; j < std::min<int>(nextJacobIndex, nPairs); j++)
			PmergeMe::_binaryInsertVect(sorted, toSort[j], inserted++ + j);
		currJacobIndex = nextJacobIndex;
		index++;
		
	} while (currJacobIndex < nPairs);
	if (vectInput.size() % 2)
		PmergeMe::_binaryInsertVect(sorted, vectInput.back(), vectInput.size() - 1);
}

void	PmergeMe::_binaryInsertVect(intVect& vect, int newItem, unsigned int max_range ) const noexcept
{
	intVect::iterator iter = std::upper_bound(vect.begin(), vect.begin() + max_range, newItem);
	vect.insert(iter, newItem);
}

void	PmergeMe::_sortVectPairs(std::vector<pair>& toSort) const noexcept
{
	int j;

	for (size_t i=1; i<toSort.size(); i++)
	{
		j = i - 1;
		while ((j >= 0) && (toSort[j].first < toSort[j + 1].first))
		{
			std::swap(toSort[j + 1], toSort[j]);
			j--;
		}
	}
}

void	PmergeMe::_splitAndSortList( intList const& listInput, intList& sorted, intList& toSort ) const noexcept
{
	std::list<pair>				listPairs;
	intList::const_iterator 	curr = listInput.begin();
	intList::const_iterator 	next = std::next(curr);
	intList::const_iterator		lastItem = listInput.end();

	if ((listInput.size() % 2) != 0)
		lastItem--;
	while (curr != lastItem)
	{
		if (*curr > *next)
			listPairs.push_back(pair({*curr, *next}));
		else
			listPairs.push_back(pair({*next, *curr}));
		curr = std::next(next);
		next = std::next(curr);
	}
	_sortListPairs(listPairs);
	for (auto it=listPairs.rbegin(); it != listPairs.rend(); it++)
	{
		sorted.push_back((*it).first);
		toSort.push_back((*it).second);
	}
	if (lastItem != listInput.end())
		toSort.push_back(*lastItem);
}

void	PmergeMe::_mergeInsertList( intList& sorted, intList& toSort ) const noexcept
{
	unsigned int		index = 1;
	intList::iterator	currJacobIter = toSort.begin();
	intList::iterator	nextJacobIter = toSort.begin();
	intList::iterator	sortedJacobIter = sorted.begin();

	if (toSort.empty() == true)
		return;
	sorted.insert(sorted.begin(), *currJacobIter);
	do
	{
		PmergeMe::_advanceIter(nextJacobIter, toSort.end(), this->_jacobNumbers[index] - 1 - this->_jacobNumbers[index - 1]);
		PmergeMe::_advanceIter(sortedJacobIter, sorted.end(), this->_jacobNumbers[index] - 1 - this->_jacobNumbers[index - 1]);
		if (nextJacobIter != toSort.end())
			PmergeMe::_binaryInsertList(sorted, *nextJacobIter, sorted.begin(), sortedJacobIter);
		std::advance(currJacobIter, 1);
		while (currJacobIter != nextJacobIter)
		{
			PmergeMe::_binaryInsertList(sorted, *currJacobIter, sorted.begin(), sortedJacobIter);
			std::advance(currJacobIter, 1);
		}
		index++;
	}	while (nextJacobIter != toSort.end());
}

void	PmergeMe::_binaryInsertList(intList& list, int newItem, intList::iterator start, intList::iterator end ) const noexcept
{
	intList::iterator iter = std::upper_bound(start, end, newItem);
	list.insert(iter, newItem);
}

void	PmergeMe::_sortListPairs(std::list<pair>& toSort) const noexcept
{
	std::list<pair>::iterator it, jt1, jt2;
	bool endLoop;

	it = toSort.begin();
	it++;
	for (; it!=toSort.end(); it++)
	{
		jt1 = it;
		jt2 = jt1--;
		while ((*jt1).first < (*jt2).first)
		{
			endLoop = jt1 == toSort.begin();
			std::swap(*jt1, *jt2);
			jt1--;
			jt2--;
			if (endLoop)
				break;
		}
	}
}

void	PmergeMe::_printSorted(size_t nItems, int time, const char* contName) const noexcept
{
	float	milliSecs = float(time) / 1000.f;
	std::cout << " - time to process " << nItems << " elements in std::" << contName << ": " << milliSecs << " (milliseconds)" << std::endl;
}

template <typename Iterator>
void	PmergeMe::_advanceIter(Iterator& iter, Iterator iterMax, unsigned int amount ) const noexcept
{
	while (amount--)
	{
		std::advance(iter, 1);
		if (iter == iterMax)
			return ;
	}
}
