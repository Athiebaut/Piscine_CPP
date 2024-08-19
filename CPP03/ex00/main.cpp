/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:03 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/15 18:24:02 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
	ClapTrap *a = new ClapTrap("Elsa");
	ClapTrap *b = new ClapTrap("Antoine");

	a->attack("Alix");
	a->takeDamage(5);
	a->beRepaired(10);
	b->attack("Elisa");
	b->takeDamage(20);
	b->beRepaired(10);
	delete(a);
	delete(b);
	return 0;
}