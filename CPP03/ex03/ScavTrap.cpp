/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:49:22 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/16 17:18:23 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**********Forme canonique & co**********/

ScavTrap::ScavTrap()
{
	setHP();
	setEP();
	setAD();
	std::cout << "ScavTrap: default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	_name = name;
	setHP();
	setEP();
	setAD();
	std::cout << "ScavTrap: " << _name << " parametrized constructor called" << std::endl;
	
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	*this = other;
	std::cout << "ScavTrap: copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_Hitpoints = other._Hitpoints;
		this->_Energypoints = other._Energypoints;
		this->_Attackdamage = other._Attackdamage;
	}
	std::cout << "ScavTrap: copy assignement operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: destructor called" << std::endl;
}

/**********Other**********/

void	ScavTrap::attack(const std::string& target)
{
	if (this->_Hitpoints <= 0 || this->_Energypoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is too wasted to attack." << std::endl;
		return ;
	}
	this->_Energypoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_Attackdamage << " point(s) of damage." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_Hitpoints <= 0 || this->_Energypoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is too wasted to do anything." << std::endl;
		return ;
	}	
	std::cout << "ScavTrap " << this->_name << " is guarding the gate."<< std::endl;
}

/**********Setter**********/

void ScavTrap::setName (std::string name)
{
    this->_name = name;
    return;
}

void ScavTrap::setHP(void)
{
    this->_Hitpoints = 100;
    return;
}

void ScavTrap::setEP(void)
{
    this->_Energypoints = 50;
    return;
}

void ScavTrap::setAD(void)
{
    this->_Attackdamage = 20;
    return;
}

/**********Getter**********/

std::string ScavTrap::getName (void) const
{
    return this->_name;
}

int	ScavTrap::getHP (void) const
{
    return this->_Hitpoints;
}

int	ScavTrap::getEP (void) const
{
    return this->_Energypoints;
}

int	ScavTrap::getAD (void) const
{
    return this->_Attackdamage;
}