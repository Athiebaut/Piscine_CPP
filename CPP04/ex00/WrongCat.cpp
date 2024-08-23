/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:48:58 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 14:15:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat: Default Constructor Called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other) 
{
	std::cout << "WrongCat: Copy Constructor Called." << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
		_type = other.getType();
	std::cout << "WrongCat: Copy Assignment Operator Called." << std::endl;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor Called." << std::endl;
}

void		WrongCat::makeSound(void)const
{
	std::cout << "Wrongmeow !" << std::endl;
}
