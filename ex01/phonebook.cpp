/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:43:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/26 23:24:12 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	_nb = 0;
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
		std::cout << "Error ! Memory is full" << std::endl;
	return (0);
}

// int	Phonebook::select()
// {
// 	int	flag = 1;
// 	char	*index = new char[2];
	
// 	std::cout << "Please select an index :";
// 	std::cin >> index;
// 	if (std::cin.eof())
// 	{
// 		delete []index;
// 		return (-1);
// 	}
// 	 return (0);
// }

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