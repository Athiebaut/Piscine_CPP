/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:50:06 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 14:51:40 by athiebau         ###   ########.fr       */
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
		virtual void	makeSound(void) const;
		virtual Brain *getBrain( void ) const;
       		virtual void setIdea( std::string idea, int index );
        	virtual std::string getIdea( int index ) const;


	protected:
		std::string	_type;
};

#endif
