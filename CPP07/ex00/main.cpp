/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:32:27 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/23 15:53:33 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() 
{
	int a = 2;
	int b = 3;
	int c = 3;
	std::cout << GREEN << "a = " << RESET << a  << "\n" << GREEN << "b = " << RESET << b << "\n" << GREEN << "c = " << RESET<< c  << "\n" << std::endl;
	
	::swap(a, b);
	std::cout << GREEN << "a = " << RESET << a  << "\n" << GREEN << "b = " << RESET << b << "\n" << GREEN << "c = " << RESET<< c  << "\n" << std::endl;
	std::cout << GREEN << "min(a, b) = " << RESET << ::min(a, b) << std::endl;
	std::cout << GREEN << "max(a, b) = " << RESET <<::max(a, b) << std::endl;
	std::cout << GREEN << "max(b, c) = " << RESET << ::max(b, c) << "\n-----------------------------------------" << std::endl;
	
	std::string d = "chaine1";
	std::string e = "chaine2";
	std::string f = "chaine2";
	std::cout << BLUE << "d = " << RESET << d << "\n" << BLUE << "e = " << RESET << e << "\n" << BLUE << "f = " << RESET<< f << "\n" << std::endl;
	
	::swap(d, e);
	std::cout << BLUE << "d = " << RESET << d << "\n" << BLUE << "e = " << RESET << e << "\n" << BLUE << "f = " << RESET<< f << "\n" << std::endl;
	std::cout << BLUE << "min(d, e) = " << RESET << ::min(d, e) << std::endl;
	std::cout << BLUE << "max(d, e) = " << RESET <<::max(d, e) << std::endl;
	std::cout << BLUE << "max(e, f) = " << RESET << ::max(e, f) << std::endl;
	
	return (0);
}