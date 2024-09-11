/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:06 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:22:45 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal 
{
	public:
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &other);
		virtual ~Animal();
		Animal &operator=(Animal const &other);
		
		std::string	getType() const;
		virtual Brain *getBrain() const = 0;
        	virtual std::string getIdea(int index) const = 0;
		virtual void setIdea(std::string idea, int index) = 0;

		virtual void	makeSound() const = 0;

	protected:
		std::string	_type;
};

#endif
