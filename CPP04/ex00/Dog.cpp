/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:52:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:17:54 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
	this->_type = "Dog";
	std::cout << "Dog: default constructor called." << std::endl;
}

Dog::Dog(const Dog &other): Animal(other) 
{
	std::cout << "Dog: copy constructor called." << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) 
{
	std::cout << "Dog: assignation operator called." << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}

Dog::~Dog() 
{
	std::cout << "Dog: destructor called." << std::endl;
}

void Dog::makeSound() const 
{
	std::cout << "Woof !" << std::endl;
}
