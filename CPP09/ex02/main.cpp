/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:18:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/11/08 17:06:34 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// bool	isSorted(std::vector<int> &arr)
// {
// 	for(size_t i = 0; i < arr.size(); i++)
// 	{
// 		if (i + 1 < arr.size() && arr[i] > arr[i + 1])
// 			return (false);
// 	}
// 	return (true);
// }

bool	isSorted(std::list<int> &arr)
{
	for(std::list<int>::iterator i = arr.begin(); i != arr.end(); i++)
	{
		int span = *i;
		if (span > span + 1)
			return (false);
	}
	return (true);
}

int main(int ac, char** av)
{
	PmergeMe p;

	if (!p.isValid(ac, av))
		return (1);
		
	/*--------------------------*/
	/*--------- VECTOR ---------*/
	/*--------------------------*/
	std::cout << "SORT WITH VECTOR" << std::endl;
	std::vector<int> vec;
	for (int i = 1; i < ac; ++i) {
		vec.push_back(std::atoi(av[i]));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << RED << vec[i] << " " << RESET;
	std::cout << std::endl;

	std::clock_t start = std::clock();
	p.mergeInsertionSort(vec);
	std::clock_t end = std::clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	// if (!isSorted(vec))
	// {
	// 	std::cerr << "Error: Array not sorted." << std::endl;
	// 	return (1);
	// } 
	std::cout << "\nAfter:  ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << GREEN << vec[i] << " " << RESET;
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "  <<
	std::fixed << std::setprecision(6) << elapsed_time << " sec" << std::endl;

	/*--------------------------*/
	/*---------- LIST ----------*/
	/*--------------------------*/
	std::cout << "SORT WITH LIST" << std::endl;
	std::list<int> list;
	for (int i = 1; i < ac; ++i) {
		list.push_back(std::atoi(av[i]));
	}

	std::cout << "Before: ";
	for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
	{
		int span = *i;
		std::cout << RED << span << " " << RESET;
	}
	std::cout << std::endl;

	std::clock_t start2 = std::clock();
	p.mergeInsertionSort(list);
	std::clock_t end2 = std::clock();
	double elapsed_time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;

	// if (!isSorted(list))
	// {
	// 	std::cerr << "Error: Array not sorted." << std::endl;
	// 	return (1);
	// } 
	std::cout << "\nAfter:  ";
	for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
	{
		int span = *i;
		std::cout << GREEN << span << " " << RESET;
	}
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : "  <<
	std::fixed << std::setprecision(6) << elapsed_time2 << " sec" << std::endl;

	return (0);
}
