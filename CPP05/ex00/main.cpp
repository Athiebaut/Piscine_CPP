/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:21:58 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:53:06 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat *ab = new Bureaucrat("ab", 3);
		Bureaucrat *ac = new Bureaucrat("ac", 149);
		// Bureaucrat *ad = new Bureaucrat("ad", 160);
		try 
		{
			std::cout << "---------------------" << std::endl;
			std::cout << "Test 1" << std::endl;
			std::cout << *ab << std::endl;
			ab->incGrade();
			std::cout << *ab << std::endl;
			ab->incGrade();
			std::cout << *ab << std::endl;
			ab->incGrade();
			std::cout << *ab << std::endl;
		} catch (std::exception& a) 
		{
			std::cout << "\033[31m" << a.what() << "\033[0m" << std::endl << std::endl;
		}
		try 
		{
			std::cout << "---------------------" << std::endl;
			std::cout << "Test 2" << std::endl;
			std::cout << *ac << std::endl;
			ac->decGrade();
			std::cout << *ac << std::endl;
			ac->decGrade();
			std::cout << *ac << std::endl;
			ac->decGrade();
			std::cout << *ac << std::endl;
		} catch (std::exception& a) 
		{
			std::cout << "\033[31m" << a.what() << "\033[0m" << std::endl << std::endl;
		}
		delete ab;
		delete ac;
		// delete ad;
	}
	catch (std::exception& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
}