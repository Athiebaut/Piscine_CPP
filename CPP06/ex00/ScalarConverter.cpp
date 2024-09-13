/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:47:32 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/13 16:13:29 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(std::string const arg)
{
	if (arg.length() == 1 && !isdigit(arg[0]))
		return (true);
	if (arg.length() == 3 && arg[0] == '\'' && arg[1] == '\'')
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
		if (isdigit(arg[i]) || (arg[i] == 'E' || arg[i] == 'e' && (arg[i + 1] == '-' || arg[i + 1] == '+' && i++)) || (arg[i] == '.' && dot == 0))
			if (arg[i] == '.')
				dot = 1;
		else
			return (false);
	}
	return (true);
}

bool ScalarConverter::isOverflow(std::string const arg)
{
	
}

