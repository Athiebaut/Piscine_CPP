/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:10:24 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 18:07:46 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**********Constructors/Destructor**********/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentPardonForm", "none", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentPardonForm", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(getName(), getTarget(), getSignGrade(), getExecGrade())
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return (*this);
}

/**********Others**********/

void	PresidentialPardonForm::execute(const Bureaucrat &exec) const
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
		std::cout << this->getTarget() << " has been pardoned by Xavier Niel and spanked by Nicolas Sadirac in the holodeck" << std::endl;
}