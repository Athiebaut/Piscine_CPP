/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:51:45 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:30:29 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal 
{
	public:
		Cat();
		Cat(Cat const &other);
		~Cat();
		Cat &operator=(Cat const &other);
		
		Brain *getBrain() const;
        	std::string getIdea(int index) const;
		void setIdea(std::string idea, int index);

		void makeSound() const;
		
	private:
		Brain* _brain;
};

#endif
