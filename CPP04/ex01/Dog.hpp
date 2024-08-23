/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:53:50 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 15:46:25 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal 
{
	public:
		Dog(void);
		Dog(Dog const &other);
		~Dog(void);
		Dog &operator=(Dog const &other);
		
		void makeSound() const;
		Brain *getBrain( void ) const;
       		void setIdea( std::string idea, int index );
        	std::string getIdea( int index ) const;

	private:
		Brain* _brain;
};

#endif
