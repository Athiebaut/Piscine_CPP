/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:03:35 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/29 11:04:53 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{

	BitcoinExchange b;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <filename>"  << std::endl;
		return 1;
	}
	b.readDataCSV();
	b.readDataTxt(argv[1]);
	return (0);
}