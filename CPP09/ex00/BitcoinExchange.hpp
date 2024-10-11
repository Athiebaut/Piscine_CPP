/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:28:12 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/11 15:45:28 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

const std::string csvFile = "data.csv";

class BitcoinExchange
{
	private:
		std::map<const std::string, double> _mapExchangesData;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::map<const std::string, double> getMapExchangeRates() const;
		// std::map<const std::string, double> getMapInputData(void) const;

		void readDataCSV();

		bool checkDataCSV();

		
};

#endif