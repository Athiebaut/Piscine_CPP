/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:18:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/11/16 19:28:54 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	PmergeMe p;
	
	/*--------------------------*/
	/*--------- VECTOR ---------*/
	/*--------------------------*/	
	std::vector<int> vec;
	
	std::clock_t start = std::clock();
	if (!p.isValid(ac, av))
		return (1);
		
	std::cout << BLUE << "\nSORT WITH VECTOR\n" << RESET << std::endl;
	
	for (int i = 1; i < ac; ++i) 
		vec.push_back(std::atoi(av[i]));

	std::cout << "\033[1m" << "BEFORE: " << RESET;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << RED << vec[i] << " " << RESET;
	std::cout << std::endl;

	p.mergeInsertionSort(vec);
	std::clock_t end = std::clock();
	double elapsed_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
	
	std::cout << "\033[1m" << "\nAFTER:  " << RESET;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << GREEN << vec[i] << " " << RESET;
	std::cout << std::endl << std::endl;
	
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "  <<
	std::fixed << std::setprecision(6) << "\033[38;5;214m" << elapsed_time << RESET << " ms" << std::endl;

	// /*--------------------------*/
	// /*--------- DEQUE ----------*/
	// /*--------------------------*/
	std::deque<int> deq;
	
	start = std::clock();
	if (!p.isValid(ac, av))
		return (1);
	
	std::cout << BLUE << "\nSORT WITH DEQUE\n" << RESET << std::endl;

	for (int i = 1; i < ac; ++i)
		deq.push_back(std::atoi(av[i]));

	std::cout << "\033[1m" << "BEFORE: " << RESET;
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << RED << deq[i] << " " << RESET;
	std::cout << std::endl;

	p.mergeInsertionSort(deq);
	end = std::clock();
	elapsed_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;

	std::cout << "\033[1m" << "\nAFTER:  " << RESET;
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << GREEN << deq[i] << " " << RESET;
	std::cout << std::endl << std::endl;
	
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : "  <<
	std::fixed << std::setprecision(6) << "\033[38;5;214m" << elapsed_time << RESET << " ms" << std::endl;

	return (0);
}
