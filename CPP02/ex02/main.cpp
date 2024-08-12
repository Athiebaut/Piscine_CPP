/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:24 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/12 17:12:50 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main() 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}