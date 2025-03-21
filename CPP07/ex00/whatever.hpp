/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:32:56 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/23 15:44:09 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

template <typename T> void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T> T max(T a, T b)
{
	return (a > b ? a : b);
}

#endif