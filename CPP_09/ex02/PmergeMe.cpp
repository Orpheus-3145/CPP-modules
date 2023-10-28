/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 21:21:03 by fra           #+#    #+#                 */
/*   Updated: 2023/10/28 03:53:02 by fra           ########   odam.nl         */
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
void PmergeMe::sortInput<std::vector<int> >( void ) const noexcept
{
	std::vector<int>	vectInput = this->_toVector();
	unsigned int		nPairs = vectInput.size() / 2;
	std::vector<int>	sorted;
	std::vector<int>	toSort;
	std::vector<pair>	tmp;

	for (unsigned int i=0; i<nPairs; i++)
	{
		if (vectInput[i * 2] > vectInput[i * 2 + 1])
		{
			sorted.push_back(vectInput[i * 2]);
			toSort.push_back(vectInput[i * 2 + 1]);
		}
		else
		{
			sorted.push_back(vectInput[i * 2 + 1]);
			toSort.push_back(vectInput[i * 2]);
		}
	}
	if (vectInput.size() % 2)
		sorted.push_back(vectInput.back());
	std::sort(sorted.begin(), sorted.end());
	// for (unsigned int i=0; i<nPairs;)
	// {
	// 	int toInsert = toSort[this->_generateJacobsthal(i)]
	// }
	// std::cout << this->_inputString << std::endl;
	// for (auto tmp1 : tmp)
	// 	std::cout << std::setw(9) <<tmp1.first;
	// // if (last != -1)
	// // 	std::cout << std::setw(9) << last;
	// std::cout << std::endl;
	// for (auto tmp1 : tmp)
	// 	std::cout << std::setw(9) << tmp1.second;
	// std::cout << std::endl;
	// for (auto tmp1 : sorted)
	// 	std::cout << std::setw(4) << tmp1;
	// std::cout << std::endl;
}

template <>
void PmergeMe::sortInput<std::list<int> >( void ) const noexcept
{
	std::list<int>		listInput = this->_toList();
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

int		PmergeMe::_generateJacobsthal( int index ) const noexcept
{
	if (index == 0)
		return (1);
	else if (index == 1)
		return (3);
	else
		return ( _generateJacobsthal(index - 1) + _generateJacobsthal(index - 2) * 2);
}

void	PmergeMe::_binaryInsert(std::vector<int>& vect, int newItem) const noexcept
{
	int start, mid, end;
	std::vector<int>::iterator iter = vect.begin();

	start = 0;
	end = vect.size() - 1;
	std::cout << "insert: " << newItem << "\n";
	while (end != 1)
	{
		mid = start + end / 2;
	}
	iter += mid + 1;
	vect.insert(iter, newItem);
}
