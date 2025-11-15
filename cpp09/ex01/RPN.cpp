/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:10:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/15 21:58:51 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

static bool isWhitespaceOnly(const std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

static double applyOperation(double leftOp, double rightOp, char op)
{
	switch (op)
	{
		case '+':
			return leftOp + rightOp;
		case '-':
			return leftOp - rightOp;
		case '*':
			return leftOp * rightOp;
		case '/':
			if (rightOp == 0)
				throw std::runtime_error("Impossible: Division by zero");
			return leftOp / rightOp;
		default: //this should never be reached
			throw std::runtime_error("Unknown operator");
	}
}

double RPN::executeCalc(const std::string &string)
{
	std::stack<double> rpn;

	if (string.empty() || isWhitespaceOnly(string))
		throw std::runtime_error("Empty expression");

	for (size_t i = 0; i < string.length(); i++)
	{
		char token = string[i];
		if (std::isspace(token))
			continue;
		if (std::isdigit(token))
		{
			if (std::isdigit(string[i + 1]) && i + 1 < string.length())
				throw std::runtime_error("Invalid number: multi-digit numbers are not supported");
			else if (!std::isspace(string[i + 1]) && i + 1 < string.length() && (std::isdigit(string[i + 1]) || std::string("+-*/").find(string[i + 1]) != std::string::npos))
				throw std::runtime_error("There must be a space after operands");
			
			rpn.push(static_cast<double>(token - '0'));
		}
		else if (std::string("+-*/").find(token) != std::string::npos)
		{
			if (rpn.size() < 2)
				throw std::runtime_error("Insufficient operands for operation");
			
			double rightOp = rpn.top(); //get the top element
			rpn.pop(); //remove it from stack
			double leftOp = rpn.top();
			rpn.pop();

			double result = applyOperation(leftOp, rightOp, token);
			rpn.push(result);
		}
		else
			throw std::runtime_error("Invalid character: " + std::string(1, token));
	}
	if (rpn.size() != 1)
		throw std::runtime_error("The RPN expression is invalid");
	return rpn.top();
}