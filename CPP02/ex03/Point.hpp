/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:17 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/13 21:17:52 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP 

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point(void);

		float	getX(void) const;
		float	getY(void) const;
	
	private:
		Fixed const _x;
		Fixed const _y;	
};

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif