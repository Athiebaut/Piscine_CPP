/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:15 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/09 16:57:34 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	checkGrade(int grade)
{
	if (grade > low_r)
		throw Form::GradeTooLowException();
	if (grade < high_r)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string name, bool sign, const int signGrade, const int execGrade) : _name(name), _signed(sign), _signGrade(signGrade), _execGrade(execGrade)
{
	checkGrade(_signGrade);
	checkGrade(_execGrade);
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) 
{}

Form::~Form()
{}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecGrade() const
{
	return this->_execGrade;
}

void Form::beSigned(const Bureaucrat &brc)
{
	if (brc.getGrade() <= this->_signGrade)
	{
		this->_signed = true;
		std::cout << "\033[34m" << brc.getName() << " signed " << _name << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[34m" << brc.getName() << " couldn't sign " << _name << " because " << "\033[0m";
		throw Form::GradeTooLowException();

	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Exception: grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Exception: grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "\033[34m" << "Form " << form.getName()
	   << ", status: " << (form.getSigned() ? ("\033[32m" "signed" "\033[34m") : ("\033[31m" "not signed" "\033[34m"))
	   << ", sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecGrade()
	   << "\033[0m" << std::endl;
	return os;
}
