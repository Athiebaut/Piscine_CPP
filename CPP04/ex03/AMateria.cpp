/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:35 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:34:45 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/**********Constructors/Destructor**********/

AMateria::AMateria() : _type("")
{}

AMateria::AMateria(std::string const &type) : _type(type)
{}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

/**********Getter/Setter**********/

std::string const &AMateria::getType() const
{
	return (_type);
}

/**********Others**********/

void	AMateria::use(ICharacter &target)
{
	(void)target;
	return ;
}