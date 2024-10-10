/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:28:12 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/10 16:04:51 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

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

		std::map<std::string, double> getMapExchangeRates(void) const;
		std::map<std::string, double> getMapInputData(void) const;

		void readDataCSV();

		
};

#endif