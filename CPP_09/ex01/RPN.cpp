/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 18:21:22 by fra           #+#    #+#                 */
/*   Updated: 2023/12/04 20:38:53 by fra           ########   odam.nl         */
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
	int	result;
	std::stack<int> numbers;

	std::cout << input;
	if (_checkInput(input) == false)
	{
		std::cout << " --> invalid input" << std::endl;
		return ;
	}
	auto start = input.begin();
	result = _findResult(start, input.end(), numbers);
	if (result == INT32_MAX)
		std::cout << " --> invalid input" << std::endl;
	else
		std::cout << " = " << result << std::endl;
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
				return (INT32_MAX);
			first = numbers.top();
			numbers.pop();
			if ((*currSymbol == '/') and (second == 0))
				return (INT32_MAX);
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

bool	RPN::_checkInput( std::string input )
{
	std::string symbols = "+-*/";
	std::string numbers = "0123456789 +-*/";
	int numFound=0, symFound=0;
	const char *check = input.c_str();
	while (isspace(*check))
		check++;
	if (*check == '\0')
		return (false);
	while (*check)
	{
		if (symbols.find(*check) != std::string::npos)
			symFound++;
		else if (numbers.find(*check) != std::string::npos)
			numFound++;
		else
			return (false);
		check++;
	}
	if ((*check == '\0') and ((numFound == 1) or ((numFound > 1) and (symFound > 0))))
		return (true);
	else
		return (false);
}