/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:26:34 by athiebau          #+#    #+#             */
/*   Updated: 2024/11/16 19:29:58 by athiebau         ###   ########.fr       */
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
		std::cerr << RED << "Usage: " << argv[0] << " [num...]" << RESET << std::endl;
		return (false);
	}
	
	int numbers[argc - 1];
	int count = 0;
	for (int i = 1; i < argc; ++i)
	{
		char *arg = argv[i];

		if (!isNumber(arg))
		{
			std::cerr << RED << "Error: Characters include." << RESET << std::endl;
			return false;
		}
		long num = std::atol(arg);
		if (num > INT_MAX || num < 0)
		{
			std::cerr << RED << "Error: Only positive integer sequence as argument." << RESET << std::endl;
			return false;
		}
		if (!isDuplicate(num, numbers, count))
		{
			std::cerr << RED << "Error: Duplicate number." << RESET << std::endl;
			return (false);
		}
		numbers[count] = static_cast<int>(num);
		++count;
	}
	return (true);
}

static std::vector<int> generateJacobsthal(size_t limit) 
{
	std::vector<int> jacobsthal;
	int a = 0, b = 1;
	
	while (a <= static_cast<int>(limit)) 
	{
		jacobsthal.push_back(a);
		int next = a + 2 * b;
		a = b;
		b = next;
	}
	
	return (jacobsthal);
}

void	PmergeMe::mergeInsertionSort(std::vector<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1) 
		return;
	std::vector<int> larger, smaller;

	// Step 1 and Step 2: Pairing and finding larger and smaller elements
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			larger.push_back(std::max(arr[i], arr[i + 1]));
			smaller.push_back(std::min(arr[i], arr[i + 1]));
		} else
			larger.push_back(arr[i]);
	}
	
	// Step 3: Recursively sort the larger elements
	mergeInsertionSort(larger);
	
	// Step 4: Find the corresponding smaller element for the smallest larger element
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
	arr.clear();
	arr = larger;
	if (correspondingSmaller != -1)
		arr.insert(arr.begin(), correspondingSmaller);
	
	// Step 5: Use Jacob-style to find best iterator
	std::vector<int> jacobsthal = generateJacobsthal(arr.size());
	for (size_t i = 0; i < smaller.size(); ++i) 
	{
		if (smaller[i] != correspondingSmaller) 
		{
			size_t index = 0;
			for (size_t j = 0; j < jacobsthal.size(); ++j) 
			{
				if ((unsigned long)jacobsthal[j] >= arr.size()) 
					break;
				if (arr[jacobsthal[j]] >= smaller[i]) 
				{
					index = jacobsthal[j];
					break;
				}
			}
		//  Step 6: Final insertion point refinement using binary search
		std::vector<int>::iterator it = std::lower_bound(arr.begin() + index, arr.end(), smaller[i]);
		arr.insert(it, smaller[i]);
		}
	}
}

static std::deque<int> generateJacobsthalDeque(size_t limit) 
{
	std::deque<int> jacobsthal;
	int a = 0, b = 1;
	
	while (a <= static_cast<int>(limit)) 
	{
		jacobsthal.push_back(a);
		int next = a + 2 * b;
		a = b;
		b = next;
	}
	
	return (jacobsthal);
}

void	PmergeMe::mergeInsertionSort(std::deque<int> &arr)
{
	size_t n = arr.size();
	if (n <= 1) 
		return;
	std::deque<int> larger, smaller;

	// Step 1 and Step 2: Pairing and finding larger and smaller elements
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			larger.push_back(std::max(arr[i], arr[i + 1]));
			smaller.push_back(std::min(arr[i], arr[i + 1]));
		} else
			larger.push_back(arr[i]);
	}
	
	// Step 3: Recursively sort the larger elements
	mergeInsertionSort(larger);
	
	// Step 4: Find the corresponding smaller element for the smallest larger element
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
	arr.clear();
	arr = larger;
	if (correspondingSmaller != -1)
		arr.insert(arr.begin(), correspondingSmaller);
	
	// Step 5: Use Jacob-style to find best iterator
	std::deque<int> jacobsthal = generateJacobsthalDeque(arr.size());
	for (size_t i = 0; i < smaller.size(); ++i) 
	{
		if (smaller[i] != correspondingSmaller) 
		{
			size_t index = 0;
			for (size_t j = 0; j < jacobsthal.size(); ++j) 
			{
				if ((unsigned long)jacobsthal[j] >= arr.size()) 
					break;
				if (arr[jacobsthal[j]] >= smaller[i]) 
				{
					index = jacobsthal[j];
					break;
				}
			}
		//  Step 6: Final insertion point refinement using binary search
		std::deque<int>::iterator it = std::lower_bound(arr.begin() + index, arr.end(), smaller[i]);
		arr.insert(it, smaller[i]);
		}
	}
}