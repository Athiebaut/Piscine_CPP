/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:56:01 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/07 17:22:05 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() 
{
	std::cout << BLUE << " Single Set Test "<< RESET << std::endl;

	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		std::cout << GREEN << "shortestSpan : " << sp1.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "longestSpan  : " << sp1.longestSpan() << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "  Multi Set Test " << RESET << std::endl;

	Span sp2 = Span(10002);
	try
	{
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.addNumber(100, 10000);

		std::cout << GREEN << "shortestSpan : " << sp2.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "longestSpan  : " << sp2.longestSpan() << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << " (Error) Over Size Test " << RESET << std::endl;

	Span sp3 = Span(10002);
	try
	{
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(100, 10000);
		sp3.addNumber(1);

		std::cout << GREEN << "shortestSpan: " << sp3.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "longestSpan : " << sp3.longestSpan() << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << " (Error) Too Little Size Test " << RESET << std::endl;

	Span sp4 = Span(2);
	try
	{
		sp4.addNumber(1);

		std::cout << GREEN << "shortestSpan: " << sp4.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "longestSpan : " << sp4.longestSpan() << RESET << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}