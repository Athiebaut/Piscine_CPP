/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:45:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/06/10 13:06:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	(void)	av;
	int	i = 1;
	int	j = 0;
	
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			while (av[i][j])
				std::cout << (char)toupper(av[i][j++]);
			i++;
			j = 0;
		}
		std::cout << std::endl;
	}
}