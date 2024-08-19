/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:05 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/14 17:19:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(int ac, char **av)
{
	char	*error;
	int	i = 1;
	float	f;
	bool	result;

	system("clear");
	std::cout << "Hi ! Wanna find out if your point find his way in the triangle ? Let see : ";
	if (ac < 9 || ac > 9)
	{
		std::cout << "Wrong number of arguments, please fix it." << std::endl;
		return (1);
	}
	while (i < 9)
	{
		f = strtof(av[i], &error);
		if ((error && error[0] != '\0') || !av[i])
		{
			std::cout << "Wrong arguments, please enter only numeric values." << std::endl;
			return (1);
		}
		i++;
	}
	Point A(strtof(av[1], NULL), strtof(av[2], NULL));
	Point B(strtof(av[3], NULL), strtof(av[4], NULL));
	Point C(strtof(av[5], NULL), strtof(av[6], NULL));
	Point P(strtof(av[7], NULL), strtof(av[8], NULL));

	if (!bsp(A, B, C, P))
		std::cout << "\033[31mFalse\033[0m" << std::endl;
	else
		std::cout << "\033[32mTrue\033[0m" << std::endl;
	return (0);
}
