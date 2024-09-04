/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:29:16 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/04 12:15:39 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define high_r 1
#define low_r 150

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &other);

		std::string	getName() const;
		int		getGrade() const;

		void		incGrade();
		void		decGrade();

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
		const std::string	_name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &brc);

#endif
