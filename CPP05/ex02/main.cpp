/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:30:30 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/10 17:53:38 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	/* Test 1 : Executing Shruberry Creation Form */
	std::cout << std::endl << "Leonardo Da Feeling, a bureaucrat by day and an artist by night. He will execute the schrubbery creation Form. " << std::endl << std::endl;
	Bureaucrat LeonardoDaFeeling("Leonardo Da Feeling", 20);
	ShrubberyCreationForm ShrubberyForm("Alberto");
	std::cout << "\t" << LeonardoDaFeeling << std::endl;
	std::cout << "\t" << ShrubberyForm << std::endl;
	LeonardoDaFeeling.signForm(ShrubberyForm);
	std::cout << std::endl << "\t" << ShrubberyForm << std::endl;
	LeonardoDaFeeling.executeForm(ShrubberyForm);
	std::cout << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl << std::endl;

	/*Test 2 : Robotomization Form */
	std::cout << "Kim Card-Ashian, loves playing with her barbies. This time she will robotomize-them. " << std::endl << std::endl;
	Bureaucrat KimCardAshian("Kim Card-Ashian", 45);
	RobotomyRequestForm RobotomyForm("Botox Barbie");
	std::cout << "\t" << KimCardAshian << std::endl;
	std::cout << "\t" << RobotomyForm << std::endl;
	KimCardAshian.signForm(RobotomyForm);
	std::cout << std::endl << "\t" << RobotomyForm << std::endl;
	KimCardAshian.executeForm(RobotomyForm);
	std::cout << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;

	/* Test 3: Executing Presidential Pardon Form */
	std::cout <<std::endl << "Xavier Niel, himself, allowed a student to be pardonned after being black-holed, with the Presidential Pardon Form. " << std::endl;
	std::cout << std::endl << "He was very busy buying Carrefour, so he asked the staff to do it, but because of their grade they could only sign it." << std::endl << std::endl;
	Bureaucrat XavierNiel("Xavier Niel", 1);
	Bureaucrat Staff("Staff", 25);
	PresidentialPardonForm PresidentialForm("Lazy Student");
	std::cout << "\t" << XavierNiel << std::endl;
	std::cout << "\t" << Staff << std::endl;
	std::cout << "\t" << PresidentialForm << std::endl;
	Staff.signForm(PresidentialForm);
	std::cout << std::endl << "\t" << PresidentialForm << std::endl;
	Staff.executeForm(PresidentialForm);
	std::cout << std::endl;
	XavierNiel.executeForm(PresidentialForm);
	
	return 0;
}