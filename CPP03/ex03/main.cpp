/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:29:15 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/16 17:24:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

// int    main(void)
// {
//     DiamondTrap    diams("Diams");
    
//    // std::cout << "name : " << diams.getName() << " hitpoints : " << diams.getHP() << " energypoints : " << diams.getEP() << " attackdamage : " << diams.getAD() << std::endl;
    
//     for (int i = 0; i < 25; i++)
//     {
//         diams.takeDamage(2);
//         diams.beRepaired(2);
//         diams.attack("a common bot");
//     }
//     std::cout << std::endl;

//     diams.guardGate();
//     diams.highFivesGuys();
//     diams.whoAmI();
//     std::cout << std::endl;

//     DiamondTrap    david("David");
//     david.takeDamage(100);
//     david.attack("a common bot");
//     david.guardGate();
//     david.highFivesGuys();
//     david.whoAmI();
//     std::cout << std::endl;

//     DiamondTrap delta("Delta");
//     delta.guardGate();
//     delta.guardGate();
//     delta.highFivesGuys();
//     delta.whoAmI();
//     std::cout << std::endl;
    
//     return (0);
// }

//int    main(void){
//    DiamondTrap Will("Will");
//    DiamondTrap Bob("Bob");
 
//    std::cout << std::endl;
//    Will.whoAmI();
//    Bob.whoAmI();
//    std::cout << std::endl;
//    std::cout << "Bob has : " << std::endl << Bob.getenergypoint() << " energy point " << std::endl
//        << Bob.getdamage() << " attack damage" << std::endl
//        << Bob.gethitpoint() << " hitpoint" << std::endl;
//    std::cout << "Will has : " << std::endl << Will.getenergypoint() << " energy point " << std::endl
//        << Will.getdamage() << " attack damage" << std::endl
//        << Will.gethitpoint() << " hit point" << std::endl << std::endl;
//    do {
//        if (Will.gethitpoint() <= 0)
//            break ;
//        Will.attack(Bob.getname());
//        if (Bob.gethitpoint() > 0)
//            Bob.takeDamage(Will.getdamage());
//        if (Bob.gethitpoint() <= 0)
//            break ;
//        Bob.attack(Will.getname());
//        if (Will.gethitpoint() > 0)
//            Will.takeDamage(Bob.getdamage());
//        if (Will.gethitpoint() <= 0)
//            break ;
//        Bob.guardGate();
//        Will.highFivesGuys();
//        Bob.beRepaired(2);
//        std::cout << std::endl;
//    } while (Will.getenergypoint() > 0 && Bob.getenergypoint() > 0 && Will.gethitpoint() > 0 && Bob.gethitpoint() > 0);
//    std::cout << std::endl;
//    return (0);
//}

int main()
{
    std::cout << "Creating DiamondTrap instances...\n" << std::endl;
    
    DiamondTrap dt1("DiamondBoy");
    dt1.whoAmI();
    dt1.attack("EnemyBot");
    dt1.takeDamage(30);
    dt1.beRepaired(20);
    dt1.guardGate();
    dt1.highFivesGuys();
    
    std::cout << "\nTesting copy constructor...\n" << std::endl;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();
    
    std::cout << "\nTesting assignment operator...\n" << std::endl;
    DiamondTrap dt3 ("DiamondGirl");
    dt1 = dt3;
    dt1.whoAmI();

    std::cout << "\nTesting destruction...\n" << std::endl;

    return 0;
}