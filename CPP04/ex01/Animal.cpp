/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:48:47 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 15:47:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("") 
{
	std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(std::string const &type): _type(type) 
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
	std::cout << "Unknown sound." << std::endl;
}

std::string Animal::getType() const 
{
	return this->_type;
}

Brain *Animal::getBrain( void ) const
{
    return NULL;
}

void Animal::setIdea ( std::string idea, int index)
{
    (void)idea;
    (void)index;
    return;
}

std::string Animal::getIdea ( int index ) const
{
    (void)index;
    return "";
}
