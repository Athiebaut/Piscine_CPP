/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:48:58 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:20:03 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat: default Constructor Called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other) 
{
	std::cout << "WrongCat: copy Constructor Called." << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
		_type = other.getType();
	std::cout << "WrongCat: assignment Operator Called." << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor Called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrongmeow !" << std::endl;
}
