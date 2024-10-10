/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:45:18 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/09 15:52:14 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << BLUE << "----------\nTEST WITH MUTANT STACK\n----------\n" << GREEN << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << "\n----------" << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << "\n----------" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " << mstack.top() << "\n----------" << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << BLUE << "\n---------" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "TEST WITH STD::LIST STACK\n---------\n\n" << RED;

	std::list<int> stack;
	stack.push_back(5);
	stack.push_back(17);
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "top: " << stack.back() << "\n----------" << std::endl;
	stack.pop_back();
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "top: " << stack.back() << "\n----------" << std::endl;
	stack.push_back(3);
	stack.push_back(5);
	stack.push_back(737);
	stack.push_back(0);
	std::cout << "size: " << stack.size() << std::endl;
	std::cout << "top: " << stack.back() << "\n----------" << std::endl;
	
	std::list<int>::iterator sit = stack.begin();
	std::list<int>::iterator site = stack.end();
	std::cout << "caca" << std::endl;
	while (sit != site)
	{
		std::cout << RED << *sit << "caca" << std::endl;
		++sit;
	}
	// std::cout << "caca" << std::endl;
	std::list<int> st(stack);
	return (0);
}
