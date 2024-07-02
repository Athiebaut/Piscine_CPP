/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapong.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:17:49 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 06:22:42 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{}

const std::string	&Weapon::getType(void)
{
	return(this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}