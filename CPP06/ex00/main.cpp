/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:40:18 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/17 19:16:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) 
{
	if (ac != 2) 
	{
		std::cout << "Bad arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}