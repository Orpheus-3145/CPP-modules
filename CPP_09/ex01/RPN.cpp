/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 18:21:22 by fra           #+#    #+#                 */
/*   Updated: 2023/12/14 17:39:54 by faru          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::unordered_map<char, std::function<int(int, int)> > RPN::_ops = 
{
	{'+', [] (int x, int y) -> int {return (x + y);}},
	{'-', [] (int x, int y) -> int {return (x - y);}},
	{'*', [] (int x, int y) -> int {return (x * y);}},
	{'/', [] (int x, int y) -> int {return (x / y);}},
};

void	RPN::printResult( std::string input )
{
	int				result;
	std::stack<int> numbers;

	std::cout << input;
	try
	{
		_checkInput(input);
	}
	catch (const RPNException& e)
	{
		std::cout << " --> invalid input: " << e.what() << '\n';
		return ;
	}
	auto start = input.begin();
	try
	{
		result = _findResult(start, input.end(), numbers);
	}
	catch (const RPNException& e)
	{
		std::cout << " --> invalid input: " << e.what() << '\n';
		return ;
	}
	std::cout << " = " << result << '\n';
}

int	RPN::_findResult( std::string::iterator& currSymbol, std::string::iterator end, std::stack<int>& numbers )
{
	int first, second;

	if (currSymbol == end)
		return (numbers.top());
	else
	{
		if (std::isdigit(*currSymbol) != 0)
			numbers.push(*currSymbol++ - '0');
		else if (std::string("+-*/").find(*currSymbol) != std::string::npos)
		{
			second = numbers.top();
			numbers.pop();
			if (numbers.empty() == true)
				throw (RPNException("internal error"));
			first = numbers.top();
			numbers.pop();
			if ((*currSymbol == '/') and (second == 0))
				throw (RPNException("division by 0"));
			numbers.push(_ops[*currSymbol++](first, second));
		}
		else if (isspace(*currSymbol++) == true)
		{
			while ((isspace(*currSymbol) == true) and (currSymbol != end))
				currSymbol++;
		}
		return (_findResult(currSymbol, end, numbers));
	}
}

void	RPN::_checkInput( std::string input )
{
	std::string symbols = "+-*/";
	int numsFound=0, symFound=0;
	for (char singleChar : input)
	{
		if (symbols.find(singleChar) != std::string::npos)
		{
			if (numsFound < 2)
				throw (RPNException("operator before operands"));
			symFound++;
		}
		else if (isdigit(singleChar))
			numsFound++;
		else if (isspace(singleChar) == false)
			throw (RPNException(std::string("invalid char ")));
	}
	if (numsFound != symFound + 1)
		throw (RPNException(std::string("wrong number of operands or operators")));
}
