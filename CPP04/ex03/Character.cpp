/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:40 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:36:23 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/**********Constructors/Destructor**********/

Character::Character() : ICharacter(), _name(""), _count(0)
{}

Character::Character(std::string name) : ICharacter(), _name(name), _count(0)
{}

Character::Character(const Character &other) : ICharacter(other), _name(other._name), _count(other._count)
{}

Character::~Character()
{}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = other._inventory[i]->clone();
			}
			else
				_inventory[i] = NULL;
		}
		_count = other._count;
	}
	return (*this);
}

/**********Getter/Setter**********/

std::string const &Character::getName() const
{
	return (_name);
}

/**********Others**********/

void Character::equip(AMateria *am)
{
	if (_count == 4 || !am)
		return ;
	for(int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = am;
			_count++;
			break ;
		}
	}
}

void Character::unequip(int index)
{
	if (index < 0 || index > 3 || !_inventory[index])
		return ;
	_inventory[index] = NULL;
	_count--;
}

void Character::use(int index, ICharacter &target)
{
	if (index < 0 || index > 3 || !_inventory[index])
		return ;
	_inventory[index]->use(target);
}