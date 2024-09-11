/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:15 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 18:04:57 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

static void	checkGrade(int grade)
{
	if (grade > low_r)
		throw AForm::GradeTooLowException();
	if (grade < high_r)
		throw AForm::GradeTooLowException();
}

/**********Constructors/Destructor**********/

AForm::AForm() : _name("AForm"), _signed(false), _signGrade(150), _execGrade(150), _target("none")
{}

AForm::AForm(const std::string &name, const std::string &target, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	checkGrade(_signGrade);
	checkGrade(_execGrade);
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade), _target(other._target)
{}

AForm::~AForm()
{}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

/**********Getters/Setters**********/

const std::string &AForm::getName() const
{
	return this->_name;
}

const std::string &AForm::getTarget() const
{
	return this->_target;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecGrade() const
{
	return this->_execGrade;
}

/**********Others**********/

void AForm::beSigned(const Bureaucrat &brc)
{
	if (brc.getGrade() <= this->_signGrade)
	{
		this->_signed = true;
		std::cout << "\033[34m" << brc.getName() << " signed " << _name << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[34m" << brc.getName() << " couldn't sign " << _name << " because " << "\033[0m";
		throw AForm::GradeTooLowException();

	}
}

void AForm::checkExecuted(const Bureaucrat& exec) const 
{
	if (this->_signed == false) 
	{
		std::cout << exec.getName() << " can't execute " << this->_name << " because ";
		throw AForm::NotSigned();
	}
	if (exec.getGrade() > this->_execGrade) 
	{
		std::cout << exec.getName() << " can't execute " << this->_name << " because ";
		throw AForm::GradeTooLowException();
	}
	std::cout << exec.getName() << " executed " << this->_name << std::endl;
	this->execute(exec);
}

/**********Exceptions**********/

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Exception: grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Exception: grade too low";
}

const char *AForm::NotSigned::what() const throw()
{
	return "Form not signed";
}

/**********Overload**********/

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "\033[34m" << "AForm " << form.getName()
	   << ", status: " << (form.getSigned() ? ("\033[32m" "signed" "\033[34m") : ("\033[31m" "not signed" "\033[34m"))
	   << ", sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecGrade()
	   << "\033[0m" << std::endl;
	return (os);
}
