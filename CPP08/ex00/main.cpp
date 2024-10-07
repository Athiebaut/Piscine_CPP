/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:37 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/03 13:19:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void test(T &array)
{
	try
	{
		for(int i = 0; i < 9; i++)
		{
			std::cout << BLUE << "Looking for value " << RESET << i << BLUE << " in array " << RESET << std::endl;
			typename T::iterator pos = easyfind(array, i);
			std::cout << GREEN << "Value found at index " << RESET << std::distance(array.begin(), pos) << std::endl;
		}
	}
	catch (const std::runtime_error &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main()
{
	int array[] = {42, 87, 34, 0, 15, 5, 37, 70, 49, 4, 1};

	std::cout << BLUE << "\t [VECTOR] \n" << RESET << "Array : ";
	for(int i = 0; i < 11; i++)
		std::cout << array[i] << ", ";
	std::vector<int> myVector(array, array + sizeof(array) / sizeof(int));
	std::cout << std::endl;
	test(myVector);
}