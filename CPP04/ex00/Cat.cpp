/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:17:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
	_type = "Cat";
	std::cout << "Cat: default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) 
{
	std::cout << "Cat: copy constructor called." << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) 
{
	std::cout << "Cat: assignation operator called." << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}

Cat::~Cat() 
{
	std::cout << "Cat: destructor called." << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << "Meow !" << std::endl;
}

