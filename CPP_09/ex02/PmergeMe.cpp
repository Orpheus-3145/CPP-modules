/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 21:21:03 by fra           #+#    #+#                 */
/*   Updated: 2023/10/30 21:55:21 by fra           ########   odam.nl         */
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
	// unsigned int		index;
	// unsigned int		currJacobIndex;
	// unsigned int		nextJacobIndex;

	for (unsigned int i=0; i<nPairs; i++)
	{
		if (vectInput[i * 2] > vectInput[i * 2 + 1])
			vectPairs.push_back(pair({vectInput[i * 2], vectInput[i * 2 + 1]}));
		else
			vectPairs.push_back(pair({vectInput[i * 2 + 1], vectInput[i * 2]}));
	}
	std::sort(vectPairs.begin(), vectPairs.end(), [] (pair const& x, pair const& y) -> bool {return(x.first > y.first);} );
	for (unsigned int i=0; i<nPairs; i++)
	{
		sorted.push_back(vectPairs[i].first);
		toSort.push_back(vectPairs[i].second);
	}
	// std::sort(sorted.begin(), sorted.end());
	if (vectInput.size() % 2)
		toSort.push_back(vectInput.back());
	for (auto item : sorted)
		std::cout << item << "  ";
	std::cout << std::endl;
	for (auto item : toSort)
		std::cout << item << "  ";
	std::cout << std::endl;



	
	// index = 2;
	// currJacobIndex = PmergeMe::_getJacobIndex(index) - 1;
	// // PmergeMe::_binaryInsert(sorted, toSort[currJacobIndex], sorted.begin(), std::next(sorted.begin(), ));
	// sorted.insert(toSort[currJacobIndex]);
	// // std::cout << "added: " << toSort[currJacobIndex] << "\n";
	// do
	// {
	// 	index++;
	// 	nextJacobIndex = PmergeMe::_getJacobIndex(index) - 1;
	// 	if (nextJacobIndex < nPairs)
	// 		PmergeMe::_binaryInsert(sorted, toSort[nextJacobIndex], 0, nextJacobIndex - 1);
	// 	for (int j=currJacobIndex + 1; j < std::min<int>(nextJacobIndex, nPairs); j++)
	// 		PmergeMe::_binaryInsert(sorted, toSort[j], 0, nextJacobIndex - 1);
	// 	currJacobIndex = nextJacobIndex;
	// } while (currJacobIndex < nPairs - 1);
	// for (auto item : sorted)
	// 	std::cout << item << "  ";
	// std::cout << std::endl;
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
