/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:12:22 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/03 12:31:47 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :  _name(name), _weapon(weapon)
{}

HumanA::~HumanA()
{}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with his giant " << this->_weapon.getType() <<std::endl;
}