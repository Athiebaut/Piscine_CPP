/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:04:01 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/19 12:43:42 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	_type = "";
}

Animal::Animal(std::string const type)
{
	_type = type;
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{}

std::string Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	return ;
}