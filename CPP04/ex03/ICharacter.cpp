/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:51 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:38:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

/**********Constructors/Destructor**********/

ICharacter::ICharacter()
{
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

ICharacter::ICharacter(std::string const name)
{
	(void)name;
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

ICharacter::ICharacter(const ICharacter &other)
{
	for(int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

ICharacter::~ICharacter()
{
	for(int i = 0; i < 4; ++i) 
        	_inventory[i] = NULL; 
}

ICharacter &ICharacter::operator=(const ICharacter &other)
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
	}
	return (*this);	
}

