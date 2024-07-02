/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 04:44:00 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 05:11:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	zombie_1("zombie1");
	zombie_1.announce();
	Zombie	*zombie_2 = newZombie("zombie_2");
	zombie_2->announce();
	delete zombie_2;
	randomChump("zombie_3");
	return (0);
}