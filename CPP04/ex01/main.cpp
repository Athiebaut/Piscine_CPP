/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:54:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 16:31:49 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main() 
{
	Animal *array[50];
	
	for (int i = 0; i < 50; ++i) 
	{
		if (i < 25) 
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i = 0; i < 50; ++i)
		delete array[i];
}
