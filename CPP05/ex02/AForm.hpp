/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:17 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/10 17:37:48 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &name, const std::string &target, int signGrade, int execGrade);
		AForm(const AForm &other);
		virtual ~AForm();
		AForm &operator=(const AForm &other);
	
		const std::string	&getName() const;
		const std::string 	&getTarget() const;
		bool		getSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		
		void		beSigned(const Bureaucrat &brc);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void		checkExecuted(const Bureaucrat &exec) const;
		
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	private:
		AForm();
		const std::string _name;
		bool	_signed;
		const int	_signGrade;
		const int	_execGrade;
		const std::string _target;
};

std::ostream &operator<<(std::ostream &os, AForm const &brc);

#endif