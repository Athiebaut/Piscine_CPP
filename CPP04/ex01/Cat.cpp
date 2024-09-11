/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:26:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

/**********Constructors/Destructor**********/

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat: default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) 
{
	std::cout << "Cat: copy constructor called." << std::endl;
	*this = other;
	if (other._brain) 
        	_brain = new Brain(*other._brain);
    	else
        	_brain = NULL;
}

Cat &Cat::operator=(const Cat &other) 
{
	std::cout << "cat: assignation operator called." << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
        	delete _brain;
        	if (other._brain)
            		_brain = new Brain(*other._brain);
        	else
            		_brain = NULL;
        	this->_type = other._type;
    	}
	return (*this);
}

Cat::~Cat() 
{
	delete _brain;
	std::cout << "Cat: destructor called." << std::endl;
}

/**********Getters/Setters**********/

Brain *Cat::getBrain() const
{
	return _brain;
}

std::string Cat::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return (NULL);
	return _brain->ideas[index];
}

void Cat::setIdea(std::string idea, int index)
{
	if (index < 0 || index > 99)
		return ;
	_brain->ideas[index] = idea;
}

/**********Others**********/

void Cat::makeSound() const 
{
	std::cout << "Meow !" << std::endl;
}