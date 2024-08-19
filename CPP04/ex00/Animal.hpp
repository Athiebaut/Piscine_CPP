/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:22:38 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/19 12:42:58 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string const type);
		Animal(const Animal &other);
		Animal& operator=(const Animal& other);
		~Animal();

		virtual void	makeSound() const;
		std::string	getType() const;
		
	protected:
		std::string _type;
};

#endif