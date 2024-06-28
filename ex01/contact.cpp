/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:01:34 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/28 16:54:54 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact()
{
	for (int i = 1 ; i < 5 ; i++)
		_infos[i] = std::string();
	_fields[0] = "First name";
	_fields[1] = "Last name";
	_fields[2] = "Nickname";
	_fields[3] = "Phone number";
	_fields[4] = "Darkest secret";
}

int	check_name(std::string value)
{
	for (int i = 0; value.c_str()[i]; i++)
	{
		if (isalpha(value.c_str()[i]) == 0)
			return (-1);
	}
	return (0);
}

int	check_numbers(std::string value)
{
	int	i = 1;
	
	if (value.c_str()[0] == '+')
	{
		while(value.c_str()[i])
		{
			if (i > 11 || isdigit(value.c_str()[i]) == 0)
				return (-1);
			i++;
		}
		if (i < 12)
			return (-1);
	}
	else if (value.c_str()[0] == '0')
	{
		while(value.c_str()[i])
		{
			if (i > 9 || isdigit(value.c_str()[i]) == 0)
				return (-1);
			i++;
		}
		if (i < 10)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	Contact::fill(int index)
{
	_index = index;
	for (int i = 0 ; i < 5 ; i++)
	{
		while (1)
		{
			std::cout << _fields[i] << " : ";
			std::getline(std::cin, _infos[i]);
			if (std::cin.eof())
				return (-1);
			if (_infos[i].size() == 0)
				std::cout << "Error: Invalid value. Argument needed." << std::endl;
			else if (i == 0 || i == 1)
			{
				if (check_name(_infos[i]) != 0)
					std::cout << "Error: Invalid value. Only alpha are authorized." << std::endl;
				else
					break;
			}
			else if (i == 3)
			{
				if (check_numbers(_infos[i]) != 0)
					std::cout << "Error: Invalid value. Come on, there's only two correct formats (+33- /0- )." << std::endl;
				else
					break;
			}
		}
	}
	return (0);
}

void	Contact::display_list()
{	
	std::cout << "│" << std::setw(10) << _index;
	for (int i = 0 ; i < 3 ; i++)
	{
		if (_infos[i].size() < 10)
			std::cout << "│" << std::setw(10) << _infos[i];
		else
			std::cout << "│" << _infos[i].substr(0, 9) << ".";
	}
	std::cout << "│" << std::endl;
}

void	Contact::display_select()
{
	for (int i = 0 ; i < 5 ; i++)
		std::cout << _fields[i] << " : " << _infos[i] << std::endl;
}
