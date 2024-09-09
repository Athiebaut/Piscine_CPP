/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:15:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/09 15:21:10 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{}

MateriaSource::~MateriaSource()
{}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
		IMateriaSource::operator=(other);
	return (*this);
}

void MateriaSource::learnMateria(AMateria *am)
{
	if (!am)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = am;
			return ;
		}
	}
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}