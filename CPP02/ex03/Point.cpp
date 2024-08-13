/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:14:53 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/13 21:45:27 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::Point(const Point &other): _x(other._x), _y(other._y)
{
	return ;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed)this->_x = other._x;
		(Fixed)this->_y = other._y;
	}
	return (*this);
		
}

Point::~Point(void)
{
	return ;
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}