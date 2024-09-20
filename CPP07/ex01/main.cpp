/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:02 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/20 18:01:45 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string str[] = {"Salut c'est pouet !", "Oui", "Non"};
	
	for (std::size_t i = 0; i < 9; i++)
		std::cout << "array[" << i << "] : " << array[i] << std::endl;
	for (std::size_t i = 0; i < 3; i++)
		std::cout << "str : " << str[i] << std::endl;
	std::cout << std::endl;
	
	iter(array, 9, increment<int>);
	iter(str, 3, increment<std::string>);
	
	iter(array, 9, print<int>);
	std::cout << std::endl;
	iter(str, 3, print<std::string>);
	
	std::cout << std::endl;
	return (0);
}
