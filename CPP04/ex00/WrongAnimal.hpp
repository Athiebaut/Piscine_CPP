/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:48:46 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:19:17 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal : public Animal 
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &other);

		void makeSound() const;
};



#endif
