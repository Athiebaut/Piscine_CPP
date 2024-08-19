/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:03 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/15 18:27:55 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
	ClapTrap *Mateo = new ClapTrap("Mateo");
	FragTrap *Ana = new FragTrap("Ana");
	Mateo->attack("Ana");
	Ana->takeDamage(0);
	Ana->attack("Mateo");	
	Mateo->takeDamage(30);
	Ana->beRepaired(1000);
	Ana->highFivesGuys();
	Mateo->beRepaired(20);
	delete (Mateo);
	delete (Ana);
	return 0;
}