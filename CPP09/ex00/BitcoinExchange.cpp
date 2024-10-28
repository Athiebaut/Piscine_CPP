/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:28:10 by athiebau          #+#    #+#             */
/*   Updated: 2024/10/28 13:43:57 by athiebau         ###   ########.fr       */
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

double	BitcoinExchange::getRate(std::string date) const
{
	std::map<std::string, double>::const_iterator it = _mapExchangesData.upper_bound(date);
	if (it == _mapExchangesData.begin()) {
		std::cout << "Error: no available rate for the given date or earlier." << std::endl;
		return (-1.0);
	}
	--it;
	return (it->second);
}

void BitcoinExchange::readDataCSV()
{
	std::ifstream file;
	file.open(csvFile.c_str());
	if (!file.is_open())
	{
		std::cout << RED << "Cannot open .CSV file\n" << RESET;
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

void BitcoinExchange::readDataTxt(const std::string &txtFile)
{
	std::ifstream file;
	file.open(txtFile.c_str());
	if (!file.is_open())
	{
		std::cout << RED << "Cannot open inputs file\n" << RESET;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (!isValidLine(line))
			continue;
		std::istringstream lineStream(line);
		std::string date;
		std::string rateStr;
		double rate;
		std::getline(lineStream, date, '|');
		std::getline(lineStream, rateStr);
		if (!isValidDate(date))
			continue;
		if (!isValidRate(rateStr, &rate))
			continue;
		printBitcoin(date, rateStr, rate);
	}
	file.close();
}

bool	BitcoinExchange::isValidLine(const std::string &line) const
{
	try
	{
		if (line.empty())
			return false;
		if (line.find('|') == std::string::npos)
			throw std::logic_error("bad input => " + line);
	}
	catch (std::logic_error &e)
	{
		std::cerr << RED <<"Error: " << e.what() << RESET << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	try
	{
		if (date.size() != 11)
			throw std::logic_error("bad input => " + date);
		for (int i = 0; i < 10; i++)
		{
			if (i == 4 || i == 7)
			{
				if (date[i] != '-')
					throw std::logic_error("bad input => " + date);
			}
			else
			{
				if (!std::isdigit(date[i]))
					throw std::logic_error("bad input => " + date);
			}
		}
		
		int year, month, day;
		std::istringstream issYear(date.substr(0, 4));
		std::istringstream issMonth(date.substr(5, 2));
		std::istringstream issDay(date.substr(8, 2));
		issYear >> year;
		issMonth >> month;
		issDay >> day;

		int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (month > 12 || year > 2023)
			throw std::logic_error("bad input => " + date);
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			daysInMonth[2] = 29;
		if (day > daysInMonth[month])
			throw std::logic_error("bad input => " + date);
	}
	catch (std::logic_error &e)
	{
		std::cerr <<"Error: " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidRate(const std::string &rateStr, double *rate) const
{
	std::istringstream iss(rateStr);

	try
	{
		if (!(iss >> *rate))
			throw std::logic_error("not a number");
		if (*rate < 0)
			throw std::logic_error("not a positive number.");
		if (*rate > 1000)
			throw std::logic_error("too large a number.");
	}
	catch (std::logic_error &e)
	{
		std::cerr <<"Error: " << e.what() << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::printBitcoin(const std::string& date, const std::string& rateStr, double rate)
{
	double dbRate = getRate(date);

	if (dbRate < 0)
		return ;
	dbRate *= rate;
	std::cout << date << " => " << rateStr << " = " << dbRate << std::endl;
}
