/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:40:55 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 06:50:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{}

void	HumanB::attack()
{
	std::cout << this->_name << " attacks with his giant " << this->_weapon->getType() <<std::endl;
}

void	HumanB::setWeapon(Weapon &newType)
{
	this->_weapon = (Weapon *)&newType;
}