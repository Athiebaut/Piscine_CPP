/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:52:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:27:29 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/**********Constructors/Destructor**********/

Dog::Dog() 
{
	this->_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog: default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) 
{
	std::cout << "Dog: copy constructor called." << std::endl;
	*this = other;
	if (other._brain)
       		_brain = new Brain(*other._brain);
     	else
        	_brain = NULL;
}

Dog &Dog::operator=(const Dog &other) 
{
	std::cout << "Dog: assignation operator called." << std::endl;
	if (this != &other)
	{
		if (other._brain)
            		_brain = new Brain(*other._brain);
        	else 
        		_brain = NULL;
		_type = other._type;
	}
	return (*this);
}

Dog::~Dog() 
{
	delete _brain;
	std::cout << "Dog: destructor called." << std::endl;
}

/**********Getters/Setters**********/

Brain *Dog::getBrain() const
{
	return this->_brain;
}

std::string Dog::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return (NULL);
	return _brain->ideas[index];
}

void Dog::setIdea(std::string idea, int index)
{
	if (index < 0 || index > 99)
		return ;
	_brain->ideas[index] = idea;
}

/**********Others**********/

void Dog::makeSound() const 
{
	std::cout << "Woof !" << std::endl;
}