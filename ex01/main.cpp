/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:28:05 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/26 23:12:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		main(void)
{
	bool			working(true);
	Phonebook		phonebook;
	std::string		command;

	while (working)
	{
		system("clear");
		std::cout << "Please enter a command. (ADD, SEARCH OR EXIT) : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (-1);
		if (!command.compare("ADD") && (phonebook.add()) < 0)
			break ;
		else if (!command.compare("SEARCH") && (phonebook.display_phonebook() < 0))
			break ;
		// else if (!command.compare("EXIT"))
		// 	working = false;
	}
	return (0);
}