/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:32:27 by athiebau          #+#    #+#             */
/*   Updated: 2024/09/20 12:44:20 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() 
{
	int a = 2;
	int b = 3;
	int c = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "max( b, c ) = " << ::max( b, c ) << std::endl;
	std::string d = "chaine1";
	std::string e = "chaine2";
	std::string f = "chaine2";
	::swap(d, e);
	std::cout << "d = " << d << ", e = " << e << ",f = " << f << std::endl;
	std::cout << "min( d, e ) = " << ::min( d, e ) << std::endl;
	std::cout << "max( d, e ) = " << ::max( d, e ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	return 0;
}