/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:07:51 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/10 17:43:17 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "none", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(getName(), getTarget(), getSignGrade(), getExecGrade())
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void)other;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
	if (!this->getSigned()) 
	{
		std::cout << "The form cannot be executed because ";
		throw AForm::NotSigned();
	}
	else if (this->getSignGrade() < exec.getGrade()) 
	{
		std::cout << "Form cannot be executed because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::srand(std::time(NULL));
		std::cout << "* some drilling noises *" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized succesfully" << std::endl;
		else
			std::cout << "Failed to robotomized " << this->getTarget() << std::endl;
	}
}