/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:18:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/11/09 19:35:09 by athiebau         ###   ########.fr       */
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

bool	isSorted(std::deque<int> &arr)
{
	for(size_t i = 0; i < arr.size(); i++)
	{
		if (i + 1 < arr.size() && arr[i] > arr[i + 1])
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
	std::cout << BLUE << "\nSORT WITH VECTOR\n" << RESET << std::endl;
	std::vector<int> vec;
	for (int i = 1; i < ac; ++i) {
		vec.push_back(std::atoi(av[i]));
	}

	std::cout << "\033[1m" << "BEFORE: " << RESET;
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
	
	std::cout << "\033[1m" << "\nAFTER:  " << RESET;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << GREEN << vec[i] << " " << RESET;
	std::cout << std::endl << std::endl;
	
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "  <<
	std::fixed << std::setprecision(6) << "\033[38;5;214m" << elapsed_time << RESET << " sec" << std::endl;

	/*--------------------------*/
	/*--------- DEQUE ----------*/
	/*--------------------------*/
	
	std::cout << BLUE << "\nSORT WITH DEQUE\n" << RESET << std::endl;
	std::deque<int> deq;
	for (int i = 1; i < ac; ++i) {
		deq.push_back(std::atoi(av[i]));
	}

	std::cout << "\033[1m" << "BEFORE: " << RESET;
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << RED << deq[i] << " " << RESET;
	std::cout << std::endl;

	std::clock_t start2 = std::clock();
	p.mergeInsertionSort(deq);
	std::clock_t end2 = std::clock();
	double elapsed_time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;

	// if (!isSorted(deq))
	// {
	// 	std::cerr << "Error: Array not sorted." << std::endl;
	// 	return (1);
	// } 
	std::cout << "\033[1m" << "\nAFTER:  " << RESET;
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << GREEN << deq[i] << " " << RESET;
	std::cout << std::endl << std::endl;
	
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "  <<
	std::fixed << std::setprecision(6) << "\033[38;5;214m" << elapsed_time2 << RESET << " sec" << std::endl;

	return (0);
}
