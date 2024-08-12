/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:15:08 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/12 14:50:06 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP 

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
		
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		
		static Fixed& min(Fixed& c, Fixed& d);
		static Fixed& max(Fixed& c, Fixed& d);
		static const Fixed& min(const Fixed& c, const Fixed& d);
		static const Fixed& max(const Fixed& c, const Fixed& d);
	private:	
		int			_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fx);

#endif