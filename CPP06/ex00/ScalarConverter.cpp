/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:47:32 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/19 17:10:18 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const double	ScalarConverter::isMaxDouble = std::numeric_limits<double>::max();
const float	ScalarConverter::isMaxFloat = std::numeric_limits<float>::max();
const float	ScalarConverter::positive_infinity = std::numeric_limits<double>::infinity();
const float	ScalarConverter::negative_infinity = (std::numeric_limits<double>::infinity() * -1);

/**********Checkers**********/

bool ScalarConverter::isChar(std::string const arg)
{
	if (arg.length() == 1 && !isdigit(arg[0]))
		return (true);
	if (arg.length() == 3 && arg[0] == '\'' && arg[2] == '\'')
		return (true);
	return (false);
}

bool ScalarConverter::isNb(std::string const arg)
{
	int dot = 0;
	int i = 0;

	if (arg[i] == '+' || arg[i] == '-')
		i++;
	for(int i = 0; arg[i]; i++)
	{
		if (isdigit(arg[i]) || ((arg[i] == 'E' || arg[i] == 'e') && arg[i + 1] == '+' && i++) || (arg[i] == '.' && dot == 0))
		{	
			if (arg[i] == '.')
				dot = 1;
		}
		else
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFOverflow(float const &value)
{
	return (value > isMaxFloat || value < -isMaxFloat);
}

bool ScalarConverter::isDOverflow(std::string const arg, double &value)
{
	errno = 0;
	char *str;

	value = strtod(arg.c_str(), &str);
	if (str == arg.c_str())
		return (false);
	if ((value == std::numeric_limits<double>::max() || value == std::numeric_limits<double>::min()) && errno == ERANGE)
		return (true);
	return (value > isMaxDouble || value < -isMaxDouble);
}

bool ScalarConverter::isInff(std::string const arg)
{
	return (arg == "inf" || arg == "-inf" || arg == "+inf" || arg == "inff" || arg == "+inff" || arg == "-inff");
}

/**********Converters**********/

#include <stdio.h>
void ScalarConverter::convertToInt(double value, std::ostringstream &os, int is_nan)
{
	if (is_nan)
		os << "impossible";
	else if (value > INT_MAX || value < INT_MIN)
		os << "impossible";
	else
		os << static_cast <int> (value);
}

void ScalarConverter::convertToFloat(double value, std::ostringstream &os, int is_inf)
{
	if (is_inf)
		os << (value > 0 ? "inff" : "-inff");
	else if (ScalarConverter::isFOverflow(value))
		os << "impossible";
	else if (value == std::floor(value))
		os << std::fixed << std::setprecision(1) << static_cast <float> (value) << "f";
	else
		os << static_cast <float> (value) << "f";
		
}

void ScalarConverter::convertToDouble(double value, std::ostringstream &os)
{
	if (value == std::floor(value))
		os << std::fixed << std::setprecision(1) << value;
	else
		os << value;
		
}

void ScalarConverter::convertToChar(double value, std::ostringstream &os, int is_nan)
{
	if (is_nan)
		os << "impossible";
	else if (value > CHAR_MAX || value < CHAR_MIN)
		os << "impossible";
	else if (isprint(static_cast <char> (value)))
		os << "'" << static_cast <char> (value) << "'";
	else
		os << "Non displayable";	
}

/**********Others**********/

std::string ScalarConverter::removeF(std::string arg) {

	if (arg == "inf" || arg == "-inf")
		return arg;
	if (arg[arg.length() - 1] == 'f' || arg[arg.length() - 1] == 'F')
		return arg.substr(0, arg.length() - 1);
	return arg;
}

double ScalarConverter::convertDouble( std::string arg, int is_inf, int is_nan) 
{
	std::istringstream i(arg);
	double value;

	if (ScalarConverter::isChar(arg))
	{
		if (arg.length() == 3)
			value = static_cast<double>(arg[1]);
		else
			value = static_cast<double>(arg[0]);
	}
	else if (is_inf)
	{
		if (arg[0] == '-')
			value = ScalarConverter::negative_infinity;
		else
			value = ScalarConverter::positive_infinity;
	}
	else if (isDOverflow(arg, value))
		throw std::exception();
	else if (is_nan)
		value = nan("");
	return (value);
}

void ScalarConverter::printConversions(std::ostringstream const (&outputs)[4])
{
	std::string types[4] = {"char: ", "int: ", "float: ", "double: "};
	std::string colors[4] = {"\033[36m", "\033[32m", "\033[33m", "\033[35m", };
	std::string red = "\033[31m";
	std::string reset = "\033[0m";
	std::string brightWhite = "\033[97m";

	for (int i = 0; i < 4; i++)
	{
		std::cout << colors[i] << types[i] << reset;
		if (outputs[i].str() == "impossible" )
			std::cout << outputs[i].str() << reset << std::endl;
		else if (outputs[i].str() == "Non displayable")
			std::cout << red << outputs[i].str() << reset <<std::endl;
		else
			std::cout << colors[i]<< outputs[i].str() << reset << std::endl;
	}
}


void ScalarConverter::setConversions( double value, std::ostringstream (&outputs)[4], int is_inf, int is_nan)
{
	ScalarConverter::convertToChar(value, outputs[0], is_nan);
	ScalarConverter::convertToInt(value, outputs[1], is_nan);
	ScalarConverter::convertToFloat(value, outputs[2], is_inf);
	ScalarConverter::convertToDouble(value, outputs[3]);
}

void ScalarConverter::convert(std::string arg)
{
	std::ostringstream outputs[4];
	int is_inf = 0;
	int is_nan = 0;
	
	try
	{
		if (arg.empty())
			throw std::exception();
		if (isInff(arg))
			is_inf = 1;
		if (arg == "nan")
			is_nan = 1;
		if (!isChar(arg))
		{
			arg = ScalarConverter::removeF(arg);
			if (!is_inf && !isNb(arg) && !is_nan)
				throw std::exception();
		}
        	double Value = ScalarConverter::convertDouble(arg, is_inf, is_nan);
        	setConversions(Value, outputs, is_inf, is_nan);
	}
	catch (std::exception & e)
	{
		for (int i = 0; i < 4; i++)
			outputs[i] << "impossible";
	}
	printConversions(outputs);
	return;
}

/**********Constructors/Destructor**********/

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

