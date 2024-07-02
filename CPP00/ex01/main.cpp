/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:28:05 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/28 13:49:07 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		main(void)
{
	bool			working(true);
	Phonebook		phonebook;
	std::string		command;

	system("clear");
	while (working)
	{
		std::cout << "Please enter a command. (ADD, SEARCH OR EXIT) : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (-1);
		if (!command.compare("ADD"))
		{
			if (phonebook.add() < 0)
				break ;
		}
		else if (!command.compare("SEARCH"))
		{
			if (phonebook.display_phonebook() < 0)
				break ;
		}
		else if (!command.compare("EXIT"))
			working = false;
		else
			std::cout << "Error: Wrong command." << std::endl;
	}
	return (0);
}