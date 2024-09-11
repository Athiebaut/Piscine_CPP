/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:53:50 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:31:21 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
	public:
		Dog();
		Dog(Dog const &other);
		~Dog();
		Dog &operator=(Dog const &other);
		
		Brain *getBrain() const;
        	std::string getIdea(int index) const;
		void setIdea(std::string idea, int index);

		void makeSound() const;

	private:
		Brain* _brain;
};

#endif
