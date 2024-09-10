/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:36:20 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/10 17:43:06 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "none", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(getName(), getTarget(), getSignGrade(), getExecGrade())
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &exec) const
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
		std::ofstream outfile;
		
		outfile.open((getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
		if (!outfile.is_open())
		{
			std::cout << "Error while opening file_shrubbery" << std::endl;
			return ;
		}
		outfile << "        ccee88oo" << std::endl;
		outfile << "  C8O8O8Q8PoOb o8oo" << std::endl;
		outfile << " dOB69QO8PdUOpugoO9bD" << std::endl;
		outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
		outfile << "    6OuU  /p u gcoUodpP" << std::endl;
		outfile << "        \\\\///  /douUP" << std::endl;
		outfile << "          \\\\////" << std::endl;
		outfile << "           |||/\\" << std::endl;
		outfile << "           |||\\/" << std::endl;
		outfile << "           |||||" << std::endl;
		outfile << "      .....//||||\\...." << std::endl;
		
		
	}
}