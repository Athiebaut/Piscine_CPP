/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:17:59 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/12 14:59:58 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>

class ScalarConverter
{
	public:
		static void convert(std::string const arg);

		static bool isChar(std::string const arg);
		static bool isNb(std::string const arg);
		static bool isOverflow(std::string const arg);
		static bool isInff(std::string const arg);

		static void convertToInt();
		static void convertToFloat();
		static void convertToDouble();
		static void convertToChar();
		
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);		
};

#endif