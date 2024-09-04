/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 05:15:56 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/03 12:30:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "For i = 0" << std::endl;
	Zombie *horde1 = zombieHorde(0, "oui");
	horde1->announce();

	std::cout << "For i = 1" << std::endl;
	Zombie *horde2 = zombieHorde(1, "oui");
	for(int i = 0; i < 1; i++)
		horde2[i].announce();
	delete[] horde2;
	
	std::cout << "For i = 42" << std::endl;
	Zombie *horde3 = zombieHorde(42, "oui");
	for(int i = 0; i < 42; i++)
		horde3[i].announce();
	delete[] horde3;

	return (0);
}