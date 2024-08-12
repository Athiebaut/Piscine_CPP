/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:16:31 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/12 14:00:01 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) 
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) 
{
	std::cout << "Int constructor called"  << std::endl; 
	this->_value = i << Fixed::_bits;
}

Fixed::Fixed(const float f) 
{
	std::cout << "Float constructor called"  << std::endl; 
	this->_value = roundf(f *(1 << Fixed::_bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw) 
{
    _value = raw;
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