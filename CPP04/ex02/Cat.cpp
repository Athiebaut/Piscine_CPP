/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:36 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 16:02:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(): Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) 
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
	return *this;
}

Cat::~Cat() 
{
	delete _brain;
	std::cout << "Cat: destructor called." << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << "Meow !" << std::endl;
}

Brain *Cat::getBrain( void ) const
{
    return _brain;
}

void Cat::setIdea( std::string idea, int index )
{
    _brain->ideas[index] = idea;
}

std::string Cat::getIdea( int index ) const
{
    return _brain->ideas[index];
}