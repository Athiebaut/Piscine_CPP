/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:51:45 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/23 15:45:56 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>


class Cat: public Animal 
{
	public:
		Cat(void);
		Cat(Cat const &other);
		~Cat(void);
		Cat &operator=(Cat const &other);
		
		void makeSound() const;
		Brain *getBrain( void ) const;
        	void setIdea( std::string idea, int index );
        	std::string getIdea( int index ) const;
	private:
		Brain* _brain;
};

#endif
