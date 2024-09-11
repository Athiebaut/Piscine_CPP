/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:48:47 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:16:58 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("") 
{
	std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(std::string const &type) : _type(type) 
{
	std::cout << "Animal: Parametrized constructor called." << std::endl;
}

Animal::Animal(const Animal &other) 
{
	std::cout << "Animal: Copy constructor called." << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) 
{
	std::cout << "Animal: Asignation operator called." << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal: Destructor called." << std::endl;
}

void Animal::makeSound() const 
{
	std::cout << "Animal sound." << std::endl;
}

std::string Animal::getType() const 
{
	return this->_type;
}
