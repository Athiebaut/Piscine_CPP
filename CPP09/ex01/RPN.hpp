/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:05:37 by athiebau          #+#    #+#             */
/*   Updated: 2024/11/09 17:49:34 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		float	calcRPN(const std::string &strRPN);
		void	processCharOperation(const std::string &token);
		void	processNum(const std::string &token);

	private:
		std::stack< float, std::list<float> > _stk;
};

#endif