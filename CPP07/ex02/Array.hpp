/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:06:03 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/23 16:06:05 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdio>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

/**********Class**********/

template <class T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array<T> &operator=(const Array &other);
		T &operator[](size_t index);
		const T &operator[](size_t index) const;
		unsigned int size() const;

	private:
		T *_array;
		unsigned int _size;                                                                                                                                                                                                                            
};

/**********Template**********/

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	try
	{
		_array = new T[_size]();
	}
	catch (const std::bad_alloc &e)
	{
		throw;
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(0)
{
	try
	{
		_array = new T[n]();
	}
	catch (const std::bad_alloc &e)
	{
		throw;
	}
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	try
	{
		_array = new T[other.size()]();
	}
	catch (const std::bad_alloc &e)
	{
		throw;
	}
	_size = other.size();
	for (size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
	_array = NULL;
	_size = 0;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	
	T *tmp;
	try
	{
		tmp = new T[other.size()]();
	}
	catch (const std::bad_alloc &e)
	{
		throw;
	}
	delete[] _array;
	_array = tmp;
	_size = other.size();
	for (size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return (*this);	
}

/**********Overloads**********/

template <typename T>
const T &Array<T>::operator[](size_t index) const 
{
	if (size() <= index || !_array)
		throw std::out_of_range("[Error] Index out of range");
	return _array[index];
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (size() <= index || !_array)
		throw std::out_of_range("[Error] Index out of range");
	return _array[index];
}

/**********Others**********/

template <typename T>
unsigned int Array<T>::size() const 
{ 
	return _size; 
}

#endif
