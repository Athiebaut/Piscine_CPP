/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:25 by athiebau          #+#    #+#             */
/*   Updated: 2024/08/14 17:05:08 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
    Point const ab((b.getX()) - (a.getX()), (b.getY()) - (a.getY()));
    Point const bc((c.getX()) - (b.getX()), (c.getY()) - (b.getY()));
    Point const ca((a.getX()) - (c.getX()), (a.getY()) - (c.getY()));
    
    Point const ap((point.getX()) - (a.getX()), (point.getY()) - (a.getY()));
    Point const bp((point.getX()) - (b.getX()), (point.getY()) - (b.getY()));
    Point const cp((point.getX()) - (c.getX()), (point.getY()) - (c.getY()));
    
//     std::cout << "result of first op = " << (ab.getX() * ap.getY()) - (ab.getY() * ap.getX()) << std::endl;
//     std::cout << "result of secund op = " << (bc.getX() * bp.getY()) - (bc.getY() * bp.getX()) << std::endl;
//     std::cout << "result of thirs op = " << (ca.getX() * cp.getY()) - (ca.getY() * cp.getX()) << std::endl;
            

    if ((ab.getX() * ap.getY()) - (ab.getY() * ap.getX()) > 0 && (bc.getX() * bp.getY()) - (bc.getY() * bp.getX()) > 0 && (ca.getX() * cp.getY()) - (ca.getY() * cp.getX()) > 0)
        return (true);
    if ((ab.getX() * ap.getY()) - (ab.getY() * ap.getX()) < 0 && (bc.getX() * bp.getY()) - (bc.getY() * bp.getX()) < 0 && (ca.getX() * cp.getY()) - (ca.getY() * cp.getX()) < 0)
        return (true);
    return (false);
}