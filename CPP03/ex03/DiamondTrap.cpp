/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:19:19 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 16:02:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**********Forme canonique & co**********/

DiamondTrap::DiamondTrap()
{
	_name = "";
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
	ClapTrap::_name = "DiamondTrap Default_clap_name";
	
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
 	std::cout << "DiamondTrap: parametrized constructor called" << std::endl;
	_name = name;
	FragTrap::setHP();
	ScavTrap::setEP();
	FragTrap::setAD();
    return;
	
}

DiamondTrap::DiamondTrap (const DiamondTrap &other) : ScavTrap(other), FragTrap(other)
{
    _name = other._name;
    std::cout << "DiamondTrap: copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_Hitpoints = other._Hitpoints;
		this->_Energypoints = other._Energypoints;
		this->_Attackdamage = other._Attackdamage;
	}
	std::cout << "DiamondTrap: copy assignement operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap (void)
{
    std::cout << "DiamondTrap: destructor called" << std::endl;
    return;
}

/**********Setter**********/

void DiamondTrap::setName (std::string name)
{
    this->_name = name;
    return;
}

/**********Getter**********/

std::string DiamondTrap::getName (void) const
{
    return this->_name;
}

int	DiamondTrap::getHP (void) const
{
    return this->_Hitpoints;
}

int	DiamondTrap::getEP (void) const
{
    return this->_Energypoints;
}

int	DiamondTrap::getAD (void) const
{
    return this->_Attackdamage;
}

/**********Other**********/

void DiamondTrap::whoAmI ( void )
{
    std::cout << "DiamondTrap " << _name << " says: My name is " << _name << " and my ClapTrap name is " << _name + "_clap_name" << std::endl;
    return;
}