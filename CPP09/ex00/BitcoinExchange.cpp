/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:28:10 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/11 15:45:44 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _mapExchangesData(other._mapExchangesData)
{}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_mapExchangesData = other._mapExchangesData;
	return (*this);
}

std::map<const std::string, double> BitcoinExchange::getMapExchangeRates() const
{
	return (_mapExchangesData);
}

void BitcoinExchange::readDataCSV()
{
	std::ifstream file;
	file.open(csvFile.c_str());
	if (!file.is_open())
	{
		std::cout << RED << "Cannot open file\n" << RESET;
		return ;
	}
	std::string line;
	while(std::getline(file, line))
	{
		std::istringstream lineStream(line);
		std::string date;
		std::string rateStr;
		double rate;

		std::getline(lineStream, date, ',');
		std::getline(lineStream, rateStr);

		std::istringstream(rateStr) >> rate;

		_mapExchangesData[date] = rate;
	}
	file.close();
}

bool BitcoinExchange::checkDataCSV()
{
	
}
