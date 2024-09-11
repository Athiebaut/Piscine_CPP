/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:11:00 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 18:17:56 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	/* Test 1: Creating all the forms in a loop */
	std::cout << std::endl << "Latte Mcbrew is happy to start his internship at La Poste. For his first Day he will have to create many forms. " << std::endl << std::endl;
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Intern LatteMcbrew;
	Bureaucrat CaffeineQueen("Caffeine Queen", 1);

	for (int i = 0; i < 3; i++) 
	{
		AForm *form = LatteMcbrew.makeForm(forms[i], "Caffeine_Queen");
		if (form != NULL) 
		{
			std::cout << *form << std::endl;
			CaffeineQueen.signForm(*form);
			CaffeineQueen.executeForm(*form);
			std::cout << std::endl;
			
			delete form;
		}
	}

	/* Test 2: Creating a form that doesn't exist */
	std::cout << std::endl << std::endl << "It's 14:30 and Latte McBrew, feels the afternoon slump. In his sleepyness, he makes a mistake! But fear not, for La Poste's exception handling jumps in to save the day! (Well, except for those mysteriously vanishing packages...)"
		<< std::endl << std::endl;

	LatteMcbrew.makeForm("non-existent form", "Caffeine Queen");
	std::cout << std::endl;

	return (0);
}