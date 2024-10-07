/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:15 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/23 16:05:02 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW  "\033[33m"

template <typename T, typename U> 
void iter(T *array, std::size_t length, U f)
{
	if (!array || !length || !f)
		return ;
	for (std::size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T> 
void iter(T *array, std::size_t length, T f)
{
	if (!array || !length || !f)
		return ;
	for (std::size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename U> 
void increment(U &elem)
{
	elem += 1;
}

template <typename U> 
void print(U &elem)
{
	std::cout << elem << ".";
}

#endif
