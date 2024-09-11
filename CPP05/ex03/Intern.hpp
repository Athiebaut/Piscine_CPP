/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:41:07 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/11 18:07:17 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();

		static AForm *makeShrubberyCreationForm(std::string target);
        	static AForm *makeRobotomyRequestForm(std::string target);
        	static AForm *makePresidentialPardonForm(std::string target);
        	AForm *makeForm(std::string form, std::string target);

        	class FormNotFoundException : public std::exception 
		{
            		public:
                		virtual const char *what() const throw();
        	};		
};

#endif