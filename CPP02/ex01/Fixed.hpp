/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:46:48 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/12 14:00:32 by athiebau         ###   ########.fr       */
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
	private:	
		int			_value;
		static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fx);

#endif