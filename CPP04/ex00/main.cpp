/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:54:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:18:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
	
	const WrongAnimal* meta2 = new WrongAnimal();
	const Animal* j2 = new Dog();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << j2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;

	i2->makeSound();
	j2->makeSound();
	meta2->makeSound();

	delete i2;
	delete j2;
	delete meta2;
	
	return (0);
}
