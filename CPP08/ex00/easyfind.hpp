/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:21:28 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/03 13:12:14 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

template <typename T> 
typename T::iterator easyfind(T &elem, int i)
{
	typename T::iterator pos = std::find(elem.begin(), elem.end(), i);
	if (pos == elem.end())
		throw (std::runtime_error("Value not find."));
	return (pos);
}

#endif