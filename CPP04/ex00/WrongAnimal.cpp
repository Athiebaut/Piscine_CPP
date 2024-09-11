/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:58:46 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:18:42 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
	_type = "WrongAnimal";
	std::cout << "WrongAnimal: default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): Animal(other) 
{
	std::cout << "WrongAnimal: copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) 
{
	std::cout << "WrongAnimal: assignation operator called." << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal: destructor called." << std::endl;
}

void WrongAnimal::makeSound() const 
{
	std::cout << "Wrong animal sound." << std::endl;
}