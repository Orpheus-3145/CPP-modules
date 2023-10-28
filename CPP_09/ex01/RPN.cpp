/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 18:21:22 by fra           #+#    #+#                 */
/*   Updated: 2023/10/27 20:56:13 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{
	this->_ops['+'] = [] (int x, int y) -> int {return (x + y);};
	this->_ops['-'] = [] (int x, int y) -> int {return (x - y);};
	this->_ops['*'] = [] (int x, int y) -> int {return (x * y);};
	this->_ops['/'] = [] (int x, int y) -> int {return (x / y);};
}

RPN& RPN::operator=( RPN const& )
{
	return (*this);
}

void	RPN::printResult( std::string input )
{
	int	result;

	if (this->_checkInput(input) == false)
	{
		std::cout << "invalid input" << std::endl;
		return ;
	}
	result = this->_findResult(input.begin(), input.end());
	std::cout << input << " = " << result << std::endl;
}

int	RPN::_findResult( std::string::iterator currSymbol, std::string::iterator end )
{
	static std::stack<int> numbers;
	int first, second;

	if (currSymbol == end)
		return (numbers.top());
	else
	{
		if (std::isdigit(*currSymbol) != 0)
			numbers.push(*currSymbol - '0');
		else if (std::string("+-*/").find(*currSymbol) != std::string::npos)
		{
			second = numbers.top();
			numbers.pop();
			first = numbers.top();
			numbers.pop();
			numbers.push(this->_ops[*currSymbol](first, second));
		}
		return (_findResult(++currSymbol, end));
	}
}

bool	RPN::_checkInput( std::string input ) const
{
	for (char symbol : input)
	{
		if (std::string("0123456789 +-*/").find(symbol) == std::string::npos)
			return (false);
	}
	return (!input.empty());
}