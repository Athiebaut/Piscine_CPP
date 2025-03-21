/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:46:48 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/12 18:06:40 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP 

#include <iostream>
#include <typeinfo>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
		
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:	
		int			_value;
		static const int	_bits = 8;
};

#endif