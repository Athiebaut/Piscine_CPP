/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:45:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/16 17:17:49 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**********Forme canonique & co**********/

FragTrap::FragTrap()
{
	setHP();
	setEP();
	setAD();
	std::cout << "FragTrap: default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{
	_name = name;
	setHP();
	setEP();
	setAD();
	std::cout << "FragTrap: " << _name << " parametrized constructor called" << std::endl;
	
}

FragTrap::FragTrap(FragTrap const &other)
{
	*this = other;
	std::cout << "FragTrap: copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_Hitpoints = other._Hitpoints;
		this->_Energypoints = other._Energypoints;
		this->_Attackdamage = other._Attackdamage;
	}
	std::cout << "FragTrap: copy assignement operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: destructor called" << std::endl;
}

/**********Other**********/

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " raises his hand for a high five." << std::endl;
}

/**********Getter**********/

std::string FragTrap::getName (void) const
{
    return this->_name;
}

int	FragTrap::getHP (void) const
{
    return this->_Hitpoints;
}

int	FragTrap::getEP (void) const
{
    return this->_Energypoints;
}

int	FragTrap::getAD (void) const
{
    return this->_Attackdamage;
}

/**********Setter**********/

void FragTrap::setHP(void)
{
    this->_Hitpoints = 100;
    return;
}

void FragTrap::setEP(void)
{
    this->_Energypoints = 100;
    return;
}

void FragTrap::setAD(void)
{
    this->_Attackdamage = 30;
    return;
}