/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:28:12 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/28 13:42:37 by athiebau         ###   ########.fr       */
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
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		double getRate(std::string date) const;
		std::map<const std::string, double> getMapExchangeRates() const;

		void readDataCSV();
		void readDataTxt(const std::string &file);
		void printBitcoin(const std::string& date, const std::string& rateStr, double rate);

		bool isValidLine(const std::string &line) const;
		bool isValidDate(const std::string &date) const;
		bool isValidRate(const std::string &rateStr, double *rate) const;

	private:
		std::map<const std::string, double> _mapExchangesData;	
};

#endif