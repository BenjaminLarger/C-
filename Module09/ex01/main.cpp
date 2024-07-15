/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/07/15 12:43:20 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperation(char *str)
{
	if ((str[0] == '*' || (str[0] == '-' && !isdigit(str[1])) || str[0] == '+' || str[0] == '/'))
		return (true);
	else
		return (false);
}

bool	invalidArg(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '*' && str[i] != '-' && str[i] != '+' && str[i] != '/' && str[i] != 32)
			return (true);
		if ((str[i] == '*' || (str[i] == '-' && !isdigit(str[i + 1])) || str[i] == '+' || str[i] == '/') && str[i - 1] != 32)
			return (true);			
		if ((str[i] == '*' || (str[i] == '-' && !isdigit(str[i + 1])) || str[i] == '+' || str[i] == '/') && (str[i + 1]) == 32 && ((str[i + 2] == '*' || (str[i + 2] == '-' && !isdigit(str[i + 3])) || str[i + 2] == '+' || str[i + 2] == '/')))
			return (true);			
	}
	if (str[strlen(str) - 1] != '+' && str[strlen(str) - 1]  != '-' && str[strlen(str) - 1]  != '/' && str[strlen(str) - 1]  != '*')
		throw (std::out_of_range("RPN must finish by an operation!"));
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
bool	expressionHasOperation(std::string expression)
{
	bool		hasExpression = false;
	for (int i = 0; expression[i]; i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '/' || expression[i] == '*')
			hasExpression = true;
	}
	return (hasExpression);
}
void	ReversePolishNotation(const std::string& expression)
{
	std::stack<int> 	s;
	std::istringstream	tokens(expression);
	std::string			token;
	int					value;
	int					nbOfValue = 0;

	s.push(0);
	if (expressionHasOperation(expression) == false)
		throw(std::out_of_range("Program requires at least one operation!"));
	while (tokens >> token)
	{
		if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
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
			if (s.size() < 2)
				break ;
			int operand2 = s.top();
	
			s.pop();
			s.push(performOperation(operand1, operand2, token[0]));
			
		}
	}
	std::cout << s.top() << std::endl;
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
