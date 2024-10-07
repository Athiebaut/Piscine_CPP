/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:42:00 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/07 17:07:21 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits> 
#include <stdio.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);
	
		void addNumber(int nb);
		void addNumber(int nb, unsigned int rank);
		unsigned int shortestSpan();
		unsigned int longestSpan();

	private:
		unsigned int _sizeMax;
		std::vector<int> _vector;		
};

#endif