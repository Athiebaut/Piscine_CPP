/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:24 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/13 22:39:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main() 
{
	Fixed a = 0;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c = 3;
	
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	
	std::cout << "b : " << b << std::endl;
	
	std::cout << "max(a, b) : " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "a + c : " << a.operator+(c) << std::endl;
	std::cout << "a * b : " << a.operator*(b) << std::endl;
	
	return 0;
}