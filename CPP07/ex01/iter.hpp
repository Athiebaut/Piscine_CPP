/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:41:15 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/20 17:59:07 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

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

template <typename U> void increment(U &elem)
{
	elem += 1;
}

template <typename U> void print(U &elem)
{
	std::cout << elem;
}

#endif
