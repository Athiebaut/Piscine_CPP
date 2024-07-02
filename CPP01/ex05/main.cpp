/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:07:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 11:08:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string	in;
	Harl		harl;

	std::cout << "Enter a level : ";
	std::cin >> in;
	harl.complain(in);
	return (0);
}