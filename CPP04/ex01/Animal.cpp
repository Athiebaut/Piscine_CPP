/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:48:47 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:23:03 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/**********Constructors/Destructor**********/

Animal::Animal() : _type("") 
{
	std::cout << "Animal: default constructor called." << std::endl;
}

Animal::Animal(std::string const &type): _type(type) 
{
	std::cout << "Animal: parametrized constructor called." << std::endl;
}

Animal::Animal(const Animal &other) 
{
	std::cout << "Animal: copy constructor called." << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) 
{
	std::cout << "Animal: assignation operator called." << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal: destructor called." << std::endl;
}

/**********Getters/Setters**********/

std::string Animal::getType() const 
{
	return this->_type;
}

Brain *Animal::getBrain() const
{
    return NULL;
}

std::string Animal::getIdea (int index) const
{
    (void)index;
    return "";
}

void Animal::setIdea (std::string idea, int index)
{
    (void)idea;
    (void)index;
    return ;
}

/**********Others**********/

void Animal::makeSound() const 
{
	std::cout << "Unknown sound." << std::endl;
}