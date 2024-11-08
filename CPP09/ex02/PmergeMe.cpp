/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:26:34 by athiebau          #+#    #+#             */
/*   Updated: 2024/11/08 16:15:27 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

bool PmergeMe::isNumber(char *arg)
{
	for(int i = 0; arg[i]; i++)
	{
		if (!std::isdigit(arg[i]))
			return (false);
	}
	return (true);
}

bool	PmergeMe::isDuplicate(int num, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == num)
			return (false);
	}
	return (true);
}

bool	PmergeMe::isValid(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " [num...]" << std::endl;
		return (false);
	}
	
	int numbers[argc - 1];
	int count = 0;
	for (int i = 1; i < argc; ++i)
	{
		char *arg = argv[i];

		if (!isNumber(arg))
		{
			std::cerr << "Error: Characters include." << std::endl;
			return false;
		}
		long num = std::atol(arg);
		if (num > INT_MAX || num < 0)
		{
			std::cerr << "Error: Only positive integer sequence as argument." << std::endl;
			return false;
		}
		if (!isDuplicate(num, numbers, count))
		{
			std::cerr << "Error: Duplicate number." << std::endl;
			return (false);
		}
		numbers[count] = static_cast<int>(num);
		++count;
	}
	return (true);
}

void	PmergeMe::mergeInsertionSort(std::vector<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1) 
		return;
	std::vector<int> larger, smaller;
	/*----------------------------------------------------------------*/
	// std::cout << "\narray = ";
	// for (size_t i = 0; i < n; i++)
	// {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	// Step 1 and Step 2: Pairing and finding larger and smaller elements
	// std::cout << "Step 1 & 2" << std::endl;
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			larger.push_back(std::max(arr[i], arr[i + 1]));
			smaller.push_back(std::min(arr[i], arr[i + 1]));
		} else
			larger.push_back(arr[i]);
	}
	/*----------------------------------------------------------------*/
	// std::cout << "\nsmaller = ";
	// for (size_t i = 0; i < smaller.size(); i++)
	// {
	// 	std::cout << smaller[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	// std::cout << "\nlarger = ";
	// for (size_t i = 0; i < larger.size(); i++)
	// {
	// 	std::cout << larger[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	// std::cout << "------------------------" << std::endl;
	// Step 3: Recursively sort the larger elements
	// std::cout << "Step 3" << std::endl;
	mergeInsertionSort(larger);
	
	// Step 4: Find the corresponding smaller element for the smallest larger element
	// std::cout << "Step 4" << std::endl;
	int firstLarger = larger[0];
	int correspondingSmaller = -1;
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			if (arr[i] == firstLarger || arr[i + 1] == firstLarger)
			{
				correspondingSmaller = std::min(arr[i], arr[i + 1]);
				break;
			}
		}
	}
	/*----------------------------------------------------------------*/
	// std::cout << "firstLarger = " << firstLarger << " pairingSmaller = " << correspondingSmaller << std::endl;
	// std::cout << "\nArray before = ";
	// for (size_t i = 0; i < arr.size(); i++)
	// {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	arr.clear();
	arr = larger;
	/*----------------------------------------------------------------*/
	// std::cout << "Array after = ";
	// for (size_t i = 0; i < arr.size(); i++)
	// {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	if (correspondingSmaller != -1)
		arr.insert(arr.begin(), correspondingSmaller);
	/*----------------------------------------------------------------*/
	// std::cout << "Array 2 = ";
	// for (size_t i = 0; i < arr.size(); i++)
	// {
	// 	std::cout << arr[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	// std::cout << "smaller 2 = ";
	// for (size_t i = 0; i < smaller.size(); i++)
	// {
	// 	std::cout << smaller[i] << " ";
	// }
	// std::cout << std::endl;
	/*----------------------------------------------------------------*/
	// Step 5: Insert the remaining smaller elements
	// std::cout << "Step 5" << std::endl;
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		if (smaller[i] != correspondingSmaller)
		{
			std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), smaller[i]);
			arr.insert(it, smaller[i]);
		}
	}
	/*----------------------------------------------------------------*/
// 	std::cout << "Array 3 = ";
// 	for (size_t i = 0; i < arr.size(); i++)
// 	{
// 		std::cout << arr[i] << " ";
// 	}
// 	std::cout << std::endl;
}

void	PmergeMe::mergeInsertionSort(std::list<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1) 
		return;
	std::vector<int> larger, smaller;
}
