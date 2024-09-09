/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:44 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/09 15:20:20 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &other) : AMateria(other)
{}

Cure::~Cure()
{}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "Heals " << target.getName() << "'s wounds." << std::endl;	
}