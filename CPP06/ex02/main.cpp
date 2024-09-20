/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:04:11 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/19 17:26:16 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	int random = rand() % 3;
	
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << RESET;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << RESET;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << RESET;
	return ;
}

void identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << BLUE << "A" << RESET;
		(void)a;
	}
	catch(const std::exception &e)
	{}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << GREEN << "B" <<  RESET;
		(void)b;
	}
	catch(const std::exception &e)
	{}
	try 
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << RED << "C" << RESET;
		(void)c;
	}
	catch(const std::exception &e)
	{}
}

int main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << CYAN << "Enter a random number: " << RESET;
		std::string input;
		std::getline(std::cin, input);
		try 
		{
			double seed;
			std::istringstream ss(input);
			ss >> seed;
			if (ss.fail() || !ss.eof())
				throw std::exception();
			srand(static_cast<unsigned int>(seed * time(0)));

			std::cout << std::endl << "We will generate 3 random classes 🎲" << std::endl << std::endl;
			for (int i = 0; i < 3; ++i) 
			{
				Base* obj = generate();
				std::cout << CYAN << "Random class " << i + 1 << ": " << RESET;
				identify(obj);
				std::cout << " ";
				identify(*obj);
				std::cout << std::endl;
				delete obj;
			}
		}
		catch (std::exception &e) 
		{
		std::cout << "Invalid number" << std::endl;
		return (1);
		}
	}
	else 
		std::cout << "Bad arguments\n";
	return (0);
}