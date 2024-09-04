/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:51:19 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 13:39:32 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat* ab = new Bureaucrat("ab", 150);
		Bureaucrat* ac = new Bureaucrat("ac", 20);
		Form* cd = new Form("cd", false, 25, 10);

		std::cout << std::endl << *cd << std::endl;
		try
		{
			ab->signForm(*cd);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << *cd << std::endl;
		try
		{
			cd->beSigned(*ac);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		delete ab;
		delete cd;
		delete ac;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}