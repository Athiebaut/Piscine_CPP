/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:35:43 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/09 16:52:12 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < high_r)
		throw GradeTooHighException();
	if (grade > low_r)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (other._grade < high_r)
		throw Bureaucrat::GradeTooHighException();
	if (other._grade > low_r)
		throw Bureaucrat::GradeTooLowException();
	_grade = other._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &brc)
{
	os << "\033[34m" << brc.getName() << ", bureaucrat grade " << "\033[0m" << brc.getGrade() << std::endl;
	return os;
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incGrade()
{
	_grade--;
	if (_grade < high_r)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decGrade()
{
	_grade++;
	if (_grade > low_r)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}
