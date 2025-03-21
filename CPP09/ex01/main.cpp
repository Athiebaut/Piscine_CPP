/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:31:48 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/29 11:34:43 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " < RPN >" << std::endl;
		return (1);
	}
	try
	{
		RPN r;
		std::cout << r.calcRPN(argv[1]) << std::endl;
	}
	catch (const std::logic_error &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return (0);
}
