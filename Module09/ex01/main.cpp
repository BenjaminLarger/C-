/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/07/12 09:48:17 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	invalidArg(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '*' && str[i] != '-' && str[i] != '+' && str[i] != '/' && str[i] != 32)
			return (true);
		if ((str[i] == '*' || str[i] == '-' || str[i] == '+' || str[i] == '/') && str[i - 1] != 32)
			return (true);
	}
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
			if (op1 == 0)
				throw std::out_of_range("Division by zero!");
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
	int					nbOfValue = 0;

	while (tokens >> token)
	{
		if (isdigit(token[0]))
		{
			std::istringstream iss(token);
			iss >> value;
			s.push(value);
			nbOfValue++;
		}
		else
		{
			if (nbOfValue < 2)
				throw(std::out_of_range("Not enough value to perform an operation!"));
			int operand1 = s.top();
			s.pop();
			int operand2 = s.top();
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
		if (argc != 2 || invalidArg(argv[1]) == true || argv[1][0] == '\0')
			throw (std::runtime_error(BAD_INPUT));
		ReversePolishNotation(argv[1]);
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << "Error: "  << e.what() << RESET << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "\nError: "  << e.what() << RESET << std::endl;
	}
	catch(...)
	{
		std::cout << RED << "Unknown error: " << RESET << std::endl;
	}
	
	return (0);
}
