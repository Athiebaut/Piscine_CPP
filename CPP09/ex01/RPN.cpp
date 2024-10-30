/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:31:29 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/30 11:42:19 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() 
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &other) : _stk(other._stk)
{}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stk = other._stk;
	return (*this);
}

float	RPN::calcRPN(const std::string& strRPN)
{
	// if (strRPN.size() > 100000)
	// 	throw std::logic_error("Error: Too many input argv[1]");

	std::istringstream iss(strRPN);
	std::string token;
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
			processCharOperation(token);
		else
			processNum(token);
	}
	if (_stk.size() != 1)
		throw std::logic_error("Error: invalid argv[1]");
	if (_stk.top() > 2147483647.0 || _stk.top() < -2147483648.0)
		throw std::logic_error("Error: result overflow int limits");
	return (_stk.top());
}

void RPN::processNum(const std::string &token)
{
	std::istringstream issToken(token);
	float num;
	if (issToken >> num)
	{
		if (num >= 10.0)
			throw std::logic_error("Error: over 9 => " + token);
		_stk.push(num);
	}
	else
		throw std::logic_error("Error: invalid token " + token);
}

void RPN::processCharOperation(const std::string &token)
{
	if (_stk.size() < 2)
		throw std::logic_error("Error: bad operands for " + token);
	float operand2 = _stk.top(); 
	_stk.pop();
	float operand1 = _stk.top(); 
	_stk.pop();

	if (token == "+") 
		_stk.push(operand1 + operand2);
	else if (token == "-") 
		_stk.push(operand1 - operand2);
	else if (token == "*") 
		_stk.push(operand1 * operand2);
	else if (token == "/")
	{
		if (operand2 == 0)
			throw std::logic_error("Error: division by zero");
		_stk.push(operand1 / operand2);
	}
}

