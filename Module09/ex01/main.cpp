/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/27 10:38:40 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

bool	InvalidChar(char c)
{
	if ((c < '0' || c > '9') && c != '*' && c != '-' && c != '+' && c != '/')
		return (true);
	else
		return (false);
}

int	performOperation(int op1, int op2, char operation)
{
	switch (operation)
	{
		case ('+'):
			return (op2 + op1);
		case('-'):
			return (op2 - op1);
		case ('/'):
			return (op2 / op1);
		case ('*'):
			return (op2 * op1);
		default:
			throw (std::out_of_range(""));
	}
}

void	ReversePolishNotation(const std::string& expression)
{
	std::stack<int> 	s;
	std::istringstream	tokens(expression);
	std::string			token;
	int					value;
	bool				hasValue = false;

	while (tokens >> token)
	{
		if (isdigit(token[0]))
		{
			std::istringstream iss(token);
			iss >> value;
			s.push(value);
			hasValue = true;
		}
		else
		{
			if (hasValue == false)
				throw(std::out_of_range(""));
			int	operand1 = s.top();
			s.pop();
			int	operand2 = s.top();
			s.pop();
			s.push(performOperation(operand1, operand2, token[0]));
		}
		std::cout << s.top() << " ";
	}
	std::cout << std::endl << s.top();
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error(BAD_INPUT));
		ReversePolishNotation(argv[1]);
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << "Error: "  << e.what() << RESET << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "Error"  << e.what() << RESET << std::endl;
	}
	catch(...)
	{
		std::cout << RED << "Unknown error: " << RESET << std::endl;
	}
	
	return (0);
}