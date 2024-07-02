/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:46:48 by athiebau          #+#    #+#             */
/*   Updated: 2024/07/02 18:18:56 by athiebau         ###   ########.fr       */
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
		Fixed &operateur=(const Fixed &other);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
	private:	
	int			_nb;
	static const int	_count_bits;
};

#endif