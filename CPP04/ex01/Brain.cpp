/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:11:25 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:23:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain: default constructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain: copy constructor called." << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) 
{
	std::cout << "Brain: assignation operator called." << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() 
{
	std::cout << "Brain: destructor called." << std::endl;
}
