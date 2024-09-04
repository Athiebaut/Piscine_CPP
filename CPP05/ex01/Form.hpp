/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:17 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 12:21:26 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, bool sign, int signGrade, int execGrade);
		Form(Form const &other);
		~Form();
		Form &operator=(Form const &other);
	
		const std::string	&getName() const;
		bool		getSigned() const;
		int		getSignGrade() const;
		int		getExecGrade() const;

		void		beSigned(const Bureaucrat &brc);
		
		
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
	
	private:
		const std::string _name;
		bool	_signed;
		const int	_signGrade;
		const int	_execGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &brc);

#endif