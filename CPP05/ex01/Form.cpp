/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:15 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 17:57:18 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void checkGrade(int grade)
{
	if (grade > low_r)
		throw Form::GradeTooLowException();
	if (grade < high_r)
		throw Form::GradeTooLowException();
}

/**********Constructors/Destructor**********/

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

/**********Getter/Setter**********/

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

/**********Others**********/

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

/**********Exceptions**********/

const char *Form::GradeTooHighException::what() const throw()
{
	return "Exception: grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Exception: grade too low";
}

/**********Overload**********/

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "\033[34m" << "Form " << form.getName()
	   << ", status: " << (form.getSigned() ? ("\033[32m" "signed" "\033[34m") : ("\033[31m" "not signed" "\033[34m"))
	   << ", sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecGrade()
	   << "\033[0m" << std::endl;
	return (os);
}
