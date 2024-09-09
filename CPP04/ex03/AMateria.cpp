/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:14:35 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/09 12:40:56 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{}

AMateria::AMateria(std::string const &type) : _type(type)
{}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	return ;
}