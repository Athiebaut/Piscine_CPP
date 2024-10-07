/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:34:33 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/23 16:05:33 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void ) 
{
	Array<int> x;
	std::cout << "size of empty array = "<< x.size() << std::endl << std::endl;;
	
	Array<int> a(1);
	a[0] = 2;
	
	Array<int> b(a);
	b[0] = 3;
	
	std::cout << GREEN <<  "a[0] : " << RESET << a[0] << std::endl;
	std::cout << GREEN <<  "b[0] : " << RESET << b[0] << "\n" << std::endl;
	a[0] = 4;
	std::cout << GREEN <<  "a[0] : " << RESET << a[0] << std::endl;
	std::cout << GREEN <<  "b[0] : " << RESET << b[0] << std::endl;
	std::cout << std::endl;
	
	Array<int> c;
	c = a;
	std::cout << GREEN <<  "a[0] : " << RESET << a[0] << std::endl;
	std::cout << GREEN <<  "c[0] : " << RESET << c[0] << std::endl;
	c[0] = 3;
	std::cout << GREEN <<  "a[0] : " << RESET << a[0] << std::endl;
	std::cout << GREEN <<  "c[0] : " << RESET << c[0] << std::endl;
	a[0] = 1;
	std::cout << GREEN <<  "a[0] : " << RESET << a[0] << std::endl;
	std::cout << GREEN <<  "c[0] : " << RESET << c[0] << std::endl;
	std::cout << std::endl;

	Array<int> d(5);
	std::cout << GREEN <<  "size a : " << RESET << a.size() << std::endl;
	std::cout << GREEN <<  "size d : " << RESET << d.size() << std::endl;
	std::cout << std::endl;
	
	Array<std::string> e(3);
	e[0] = "Oui";
	e[1] = "Non";
	e[2] = "Jambon";
	for(int i = 0; i < 3; i++)
		std::cout << BLUE <<  "e : " << RESET << e[i] << std::endl;
	std::cout << std::endl;
	
	const Array<std::string> f(e);
	for(int i = 0; i < 3; i++)
		std::cout << BLUE <<  "f : " << RESET << f[i] << std::endl;
	std::cout << std::endl;
	try 
	{
		std::cout << c[3] << std::endl;
	}
	catch (std::exception &a) 
	{
		std::cout << RED << a.what() << RESET << std::endl;
	}
	try 
	{
		std::cout << c[-1] << std::endl;
	}
	catch (std::exception &a) 
	{
		std::cout << RED << a.what() << RESET << std::endl;
	}
	return (0);
}