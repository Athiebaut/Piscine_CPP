/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:06 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:18:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal 
{
	public:
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &other);
		virtual ~Animal(void);
		Animal &operator=(Animal const &other);
		
		std::string	getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
