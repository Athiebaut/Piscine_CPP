/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:53:50 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:18:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal 
{
	public:
		Dog();
		Dog(Dog const &other);
		~Dog(void);
		Dog &operator=(Dog const &other);
		
		void makeSound() const;
};

#endif
