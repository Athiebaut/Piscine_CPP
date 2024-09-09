/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:51:19 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/09 17:02:37 by alix             ###   ########.fr       */
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
		catch (std::exception& a)
		{
			std::cout << "\033[31m" << a.what() << "\033[0m" << std::endl;
		}
		/*************************************************************************/
		std::cout << std::endl << *cd << std::endl;
		try
		{
			cd->beSigned(*ac);
		}
		catch (std::exception& a)
		{
			std::cout << "\033[31m" << a.what() << "\033[0m" << std::endl;
		}
		std::cout << std::endl << *cd << std::endl;
		delete ab;
		delete cd;
		delete ac;
	}
	catch (std::exception& e)
	{
		std::cout << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	return 0;
}