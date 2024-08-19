/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:02:58 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/14 14:54:56 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "";
	_Hitpoints = 10;
	_Energypoints = 10;
	_Attackdamage = 0;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_Hitpoints = 10;
	_Energypoints = 10;
	_Attackdamage = 0;
	std::cout << "Parametrized constructor called" << std::endl;
	
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_Hitpoints = other._Hitpoints;
		this->_Energypoints = other._Energypoints;
		this->_Attackdamage = other._Attackdamage;
	}
	std::cout << "Copy assignement operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_Hitpoints <= 0 || this->_Energypoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is too wasted to attack." << std::endl;
		return ;
	}
	this->_Energypoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_Attackdamage << " point(s) of damage." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hitpoints <= 0 || this->_Energypoints <= 0)
	{
		std::cout << this->_name << " is already wasted." << std::endl;
		return ;
	}
	this->_Hitpoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " point(s) of damage." << std::endl;
	if (this->_Hitpoints <= 0 || this->_Energypoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is wasted." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " : " << this->_Hitpoints << " Hitpoint(s) remain." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) 
{
	if (this->_Hitpoints <= 0 || this->_Energypoints <= 0) 
	{
		std::cout << "ClapTrap " << this->_name << " is already wasted." << std::endl;
		return;
	}
	this->_Hitpoints += amount;
	this->_Energypoints -= 1;
	std::cout << "ClapTrap " << this->_name << " has repaired " << amount << " hit point(s). " << this->_Hitpoints << " Hitpoint(s) remain."<< std::endl;
}