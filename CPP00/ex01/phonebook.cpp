/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:43:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/28 16:16:36 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	_nb = 0;
	_oldest = 1;
}

int	Phonebook::add()
{
	if (_nb < 8)
	{
		if (_contact[_nb].fill(_nb + 1) < 0)
			return (-1);
		_nb++;
	}
	else
	{
		if (_contact[_oldest - 1].fill(_oldest) < 0)
			return (-1);
		_oldest++;
		if (_oldest > 9)
		_oldest = 1;
	}
	return (0);
}

int	Phonebook::select()
{
	int	flag = 0;
	std::string	index;
	int	nb;
	
	std::cout << "Please select an index : ";
	std::getline(std::cin, index);
	if (std::cin.eof())
	{
		return (-1);
	}
	for (int i = 0; i < strlen(index.c_str()); i++)
	{
		if (!isdigit(index[i]))
			flag = 1;
	}
	nb = atoi(index.c_str());
	if (flag || std::cin.fail() || nb > _nb || nb <= 0)
	{
		std::cout << "Error: Invalid index value." << std::endl;
		return (1);
	}
	_contact[nb - 1].display_select();
	return (0);
}

int	Phonebook::display_phonebook()
{
	if (_nb == 0)
		std::cout << "Error: Phonebook is empty." << std::endl;
	else
	{
		std::cout << "│     INDEX│FIRST NAME│ LAST NAME│  NICKNAME│" << std::endl;
		for (int i = 0 ; i < _nb ; i++)
			_contact[i].display_list();
		if (select() < 0)
			return (-1);
	}
	return (0);
}