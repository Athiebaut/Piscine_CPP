/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:03 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/15 18:24:28 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() 
{
	ClapTrap *Lee = new ClapTrap("Lee");
	ScavTrap *Garance = new ScavTrap("Garance");
	Lee->attack("Garance");
	Garance->takeDamage(0);
	Garance->attack("Lee");	
	Lee->takeDamage(20);
	Garance->beRepaired(1000);
	Garance->guardGate();
	Lee->beRepaired(10);
	delete (Lee);
	delete (Garance);
	return 0;
}