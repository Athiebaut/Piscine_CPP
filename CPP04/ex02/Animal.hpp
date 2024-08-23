/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:06 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 16:25:38 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal 
{
	public:
		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &other);
		virtual ~Animal(void);
		Animal &operator=(Animal const &other);
		
		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
		virtual Brain *getBrain( void ) const = 0;
       		virtual void setIdea( std::string idea, int index ) = 0;
        	virtual std::string getIdea( int index ) const = 0;


	protected:
		std::string	_type;
};

#endif
