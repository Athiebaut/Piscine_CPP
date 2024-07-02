/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 07:15:57 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 07:20:28 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loser.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: Arguments missing." << std::endl;
		return (1);
	}	
	else if (Loser::Sed(av[1], av[2], av[3]))
		return (1);
	return (0);
}