/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:25:28 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 11:51:29 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug(void)
{
	std::cout << "J'ai oublie de mettre des chaussettes de matin. Ce n'est pas grave, la journee n'en sera pas moins bonne !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Non mais du coup c'est penible parce que j'ai marche dans l'eau en venant a l'ecole. J'ai le bout des pieds froid." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Vas-y en plus c'est en train d'imbiber la chaussure donc ca n'est pas pres de secher. Ca va sentir dans tout le cluster." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "VOILA ET MAINTENANT CA EMBAUME DANS TOUTE LA PIECE, CA PUE SES GRANDS MORTS." << std::endl;
}
void	Harl::complain(std::string level)
{
	// void	(Harl::*Fonction[4])() =
	// {
	// 	&Harl::debug,
	// 	&Harl::info,
	// 	&Harl::warning,
	// 	&Harl::error
	// };
	std::string str[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int flag = -1;
	for(size_t i = 0; i < 4; i++)
		if (level == str[i])
			flag = i;
			
	switch (flag)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}

	
}