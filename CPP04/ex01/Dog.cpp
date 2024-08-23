/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:52:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 16:02:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
	this->_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other): Animal(other) 
{
	std::cout << "Dog: Copy constructor called." << std::endl;
	*this = other;
	if (other._brain)
       		_brain = new Brain(*other._brain);
     	else
        	_brain = NULL;
}

Dog &Dog::operator=(const Dog &other) 
{
	std::cout << "Dog: Asignation operator called." << std::endl;
	if (this != &other)
	{
		if (other._brain)
            		_brain = new Brain(*other._brain);
        	else 
        		_brain = NULL;
		_type = other._type;
	}
	return *this;
}

Dog::~Dog() 
{
	delete _brain;
	std::cout << "Dog: Destructor called." << std::endl;
}

void Dog::makeSound() const 
{
	std::cout << "Woof !" << std::endl;
}

Brain *Dog::getBrain( void ) const
{
    return this->_brain;
}

void Dog::setIdea( std::string idea, int index )
{
    _brain->ideas[index] = idea;
    return;
}

std::string Dog::getIdea( int index ) const
{
    return _brain->ideas[index];
}
