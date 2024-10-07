/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:41:57 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/07 17:03:59 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _sizeMax(0), _vector(0)
{}

Span::Span(unsigned int N) : _sizeMax(N)
{}

Span::Span(const Span &other) : _sizeMax(other._sizeMax), _vector(other._vector)
{}

Span::~Span()
{}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_sizeMax = other._sizeMax;
		_vector = other._vector;
	}
	return (*this);
}

void Span::addNumber(int nb)
{
	if (_vector.size() >= _sizeMax)
		throw (std::runtime_error("Cannot add new value to vector"));
	_vector.push_back(nb);	
}

void Span::addNumber(int nb, unsigned int rep)
{
	if (_vector.size() + rep > _sizeMax)
		throw (std::runtime_error("Cannot add new value to vector"));
	_vector.insert(_vector.begin(), rep, nb);
}

unsigned int Span::shortestSpan()
{
	if (_vector.size() < 2)
		throw (std::runtime_error("Not enough values in vector"));
	sort(_vector.begin(), _vector.end());
	int shortestSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator i = _vector.begin(); i != _vector.end() - 1; i++)
	{
		int span = *(i + 1) - *i;
		shortestSpan = span < shortestSpan ? span : shortestSpan;
	}
	return (shortestSpan);
}

unsigned int Span::longestSpan()
{
	if (_vector.size() < 2)
		throw (std::runtime_error("Not enough values in vector"));
	sort(_vector.begin(), _vector.end());
	int longestSpan = *(_vector.end() - 1) - *(_vector.begin());
	return (longestSpan);
}