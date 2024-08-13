/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:07 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/13 20:32:40 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"

/*---------------Constructeurs/Destructeur---------------*/

Fixed::Fixed(void) 
{
	this->_value = 0;
}

Fixed::Fixed(const int i) 
{
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f) 
{
	this->_value = roundf(f *(1 << this->_bits));
}	

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed(void)
{}

/*---------------Operateurs de comparaison---------------*/

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

/*---------------Operateurs arithmetiques----------------*/

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res._value = (this->_value + other._value);
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res._value = (this->_value - other._value);
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;
	res = (this->toFloat() * other.toFloat());
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;
	res = (this->toFloat() / other.toFloat());
	return (res);
}

/*-----Operateurs d'incrementation et decrementation-----*/

Fixed Fixed::operator++(int)
{
	Fixed prev;
	prev = *this;
	++(this->_value);
	return (prev);	
}

Fixed Fixed::operator--(int)
{
	Fixed prev;
	prev = *this;
	--(this->_value);
	return (prev);	
}

Fixed &Fixed::operator++()
{
	++(this->_value);
	return (*this);	
}

Fixed &Fixed::operator--()
{
	--(this->_value);
	return (*this);	
}

/*-----------------Fonctions surchargees-----------------*/

Fixed& Fixed::min(Fixed& c, Fixed& d)
{
	if (c < d)
		return (c);
	return (d);
}

Fixed& Fixed::max(Fixed& c, Fixed& d)
{
	if (c > d)
		return (c);
	return (d);
}

const Fixed& Fixed::min(const Fixed& c, const Fixed& d)
{
	if (c < d)
		return (c);
	return (d);
}

const Fixed& Fixed::max(const Fixed& c, const Fixed& d)
{
	if (c > d)
		return (c);
	return (d);
}

/*------------------------Others-------------------------*/

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) 
{
	this->_value = raw;
};

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << Fixed::_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fx)
{
	os << fx.toFloat();
	return (os);
}