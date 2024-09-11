/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:48 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:38:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

/**********Constructors/Destructor**********/

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &other) : AMateria(other)
{}

Ice::~Ice()
{}

Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}

/**********Others**********/

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	 std::cout << "\033[34m* shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
}