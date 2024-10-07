/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:02 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/23 16:04:45 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iter.hpp"

int main()
{
	int array[] = {47, 48, 49, 50, 51, 52, 53, 54, 55};
	std::cout << RED << "INT" << "\n" <<  std::endl;
	iter(array, 9, print<int>);
	std::cout << std::endl;
	iter(array, 9, increment<int>);
	iter(array, 9, print<int>);
	std::cout << RESET << "\n--------------------------" << std::endl;
	
	char str_char[20] = "Salut c'est pouet !";
	std::cout << BLUE << "CHAR *" << "\n" << std::endl;
	iter(str_char, 20, print<char>);
	std::cout << std::endl;
	iter(str_char, 20, increment<char>);
	iter(str_char, 20, print<char>);
	std::cout << RESET << "\n--------------------------" << std::endl;
	
	std::string str[] = {"Salut", "Oui", "Non"};
	std::cout << GREEN << "STD::STRING" << "\n" << std::endl;
	iter(str, 3, print<std::string>);
	iter(str, 3, increment<std::string>);
	std::cout << std::endl;
	iter(str, 3, print<std::string>);
	std::cout << RESET << "\n--------------------------" << std::endl;
	
	std::cout << YELLOW << "INT & CONST INT" << "\n" << std::endl;
	iter(array, 9, print<const int>);
	iter(array, 9, increment<int>);
	std::cout << std::endl;
	iter(array, 9, print<const int>);
	std::cout << RESET << std::endl;
	
	return (0);
}
