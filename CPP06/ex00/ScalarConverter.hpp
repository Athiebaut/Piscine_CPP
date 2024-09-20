/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:17:59 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/19 13:52:12 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <sstream>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cerrno>

class ScalarConverter
{
	public:
		static void convert(std::string const arg);

		static bool isChar(std::string const arg);
		static bool isNb(std::string const arg);
		static bool isFOverflow(float const &value);
		static bool isDOverflow(std::string const arg, double &value);
		static bool isInff(std::string const arg);

		static void convertToInt(double value, std::ostringstream &os, int is_nan);
		static void convertToFloat(double value, std::ostringstream &os, int is_inf);
		static void convertToChar(double value, std::ostringstream &os, int is_nan);
		static void convertToDouble(double value, std::ostringstream &os);

		static std::string removeF(std::string arg);
		static double convertDouble(std::string arg, int is_inf, int is_nan);
		static void setConversions(double value, std::ostringstream (&outputs)[4], int is_inf, int is_nan);
		static void printConversions(std::ostringstream const (&outputs)[4]);
		static const double	isMaxDouble;
		static const float	isMaxFloat;
		static const float	negative_infinity;
		static const float	positive_infinity;
		
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);		
};

#endif