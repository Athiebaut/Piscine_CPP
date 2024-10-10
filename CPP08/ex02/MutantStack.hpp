/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:45:20 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/09 15:04:49 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <algorithm>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	typedef typename Container::iterator iterator;

	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
	~MutantStack() {}

	MutantStack& operator=(const MutantStack &other) 
	{
        	std::stack<T, Container>::operator=(other);
        	return (*this);
	}
	iterator begin() 
	{
        	return this->c.begin();
    	}

    	iterator end() 
	{
        	return this->c.end();
    	}
};

#endif