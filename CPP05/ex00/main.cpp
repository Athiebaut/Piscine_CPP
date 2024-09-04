/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:21:58 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/03 12:22:18 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
    	Bureaucrat *ab = new Bureaucrat("ab", 2);
		std::cout << *ab << std::endl;
		ab->incGrade();
		std::cout << *ab << std::endl;
		ab->incGrade();
		std::cout << *ab << std::endl;
		ab->incGrade();
		std::cout << *ab << std::endl;
		delete ab;
	} catch (std::exception& a) {
		std::cout << a.what() << std::endl;
	}
}