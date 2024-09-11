/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:10:38 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 18:16:14 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/**********Constructors/Destructor**********/

Intern::Intern()
{}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

/**********Others**********/

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string concreteName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*concreteForm[])(std::string) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	try 
	{
		for (int i = 0; i < 3; i++) 
		{
			if (concreteName[i] == form) 
			{
				std::cout << "Intern creates a " << form << " form." << std::endl;
				return concreteForm[i](target);
			}
		}
		throw FormNotFoundException();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught:" << " " << e.what() << std::endl;
		return NULL;
	}
}

/**********Exception**********/

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form does not exist");
}


