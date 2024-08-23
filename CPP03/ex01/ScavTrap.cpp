/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:49:22 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 16:02:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "";
	_Hitpoints = 100;
	_Energypoints = 50;
	_Attackdamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name)
{
	_name = name;
	_Hitpoints = 100;
	_Energypoints = 50;
	_Attackdamage = 20;
	std::cout << "ScavTrap parametrized constructor called" << std::endl;
	
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
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
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

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