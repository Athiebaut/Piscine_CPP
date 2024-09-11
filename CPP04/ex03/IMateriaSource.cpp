/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:57 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:40:02 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

/**********Constructors/Destructor**********/

IMateriaSource::IMateriaSource()
{
	for (int i = 0; i < 4; i++)
        	_inventory[i] = NULL;
    	return ;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
        	_inventory[i] = NULL;
        	if (other._inventory[i])
            		_inventory[i] = other._inventory[i]->clone();
    	}
	return ;
}

IMateriaSource::~IMateriaSource()
{	
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	return ;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{	
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		} 
        }
	return (*this);
}