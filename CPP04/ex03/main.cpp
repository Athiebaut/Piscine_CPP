/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:42:07 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:47:00 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "----------Test 1----------" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp1;
		AMateria* tmp2;
		
		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete tmp1;
		delete tmp2;
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "----------Test 2----------" << std::endl;
		ICharacter* me = new Character("me");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		me->equip(ice);
		me->equip(cure);
		me->use(0, *me);
		me->use(1, *me);

		delete ice;
		delete cure;
		delete me;
	}
	{
		std::cout << "----------Test 3----------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp1;
		AMateria* tmp2;
		
		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		me->use(0, *bob);  // This should not do anything because the materia at index 0 has been unequipped

		delete bob;
		delete tmp1;
		delete tmp2;
		delete me;
		delete src;
	}
	{
		std::cout << "----------Test 4----------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me");
		AMateria* tmp1;
		AMateria* tmp2;
		
		tmp1 = src->createMateria("ice");
		me->equip(tmp1);
		tmp2 = src->createMateria("cure");  // This should return NULL because the source has not learned "cure"
		if (tmp2 == NULL)
			std::cout << "Source has not learned cure" << std::endl;

		delete tmp2;
		delete tmp1;
		delete me;
		delete src;
	}
	{
		std::cout << "----------Test 5----------" << std::endl;
		ICharacter* me = new Character("me");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		
		me->equip(ice);
		me->equip(cure);
		me->use(0, *me);
		me->use(1, *me);
		me->use(2, *me);  // This should not do anything because there is no materia at index 2
		for (int i = 0; i < 4; i++)
			me->unequip(i); 

		delete ice;
		delete cure;
		delete me;
	}
	return (0);
}