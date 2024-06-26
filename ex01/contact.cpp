/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:01:34 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/26 21:51:35 by athiebau         ###   ########.fr       */
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

int		Contact::fill(int index)
{
	_index = index;
	for (int i = 0 ; i < 5 ; i++)
	{
		while (_infos[i].size() == 0)
		{
			std::cout << _fields[i] << " : ";
			std::getline(std::cin, _infos[i]);
			if (std::cin.eof())
				return (-1);
			if (_infos[i].size() == 0)
				std::cout << "Error! Invalid value" << std::endl;
		}
	}
	return (0);
}
