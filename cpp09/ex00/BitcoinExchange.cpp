/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:48:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/26 12:23:33 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> // for std::ifstream
#include <string> // for std::string
#include <cstdlib> // for std::atof

BitcoinExchange::BitcoinExchange() : dataFile(), dataBase() {}

BitcoinExchange::BitcoinExchange(const std::string &inputFile) : dataFile(inputFile), dataBase() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : dataFile(other.dataFile), dataBase(other.dataBase) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		dataFile = other.dataFile;
		dataBase = other.dataBase;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processDatabase()
{
	std::ifstream file("data/data.csv");
	if (!file.is_open()) {
		throw std::runtime_error("Could not open data.csv");
	}
	
	std::string line;
	std::getline(file, line); // Skip header
	
	while (std::getline(file, line))
	{
		size_t comma = line.find(',');
		std::string date = line.substr(0, comma);
		double rate = std::atof(line.substr(comma + 1).c_str());
		dataBase[date] = rate; //store data into container
	}
}

static bool checkDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); ++i) 
	{
		if (i == 4 || i == 7) // skip "-"
			continue;
		if (!std::isdigit(date[i])) //check if all characters are digits
			return false;
	}
	
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	bool leap = false;
	if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
	leap = true;
	
	int daysInMonth[] = { 31, (leap) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31 || day > daysInMonth[month - 1] || year > 2025) //bitcoin started in 2009 and this code is being written in 2025
		return false;

	return true;
}

double BitcoinExchange::findRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = dataBase.lower_bound(date); // find first date that is equal or not less than date
	if (it != dataBase.end() && it->first == date) //exact match
		return it->second;
	else if (it != dataBase.begin()) // If not found, get the closest previous date
	{
		--it;
		return it->second;
	}
	else
		return -1; // No valid rate found
}

void BitcoinExchange::processInput()
{
	std::ifstream file(dataFile);
	if (!file.is_open())
		throw std::runtime_error("Could not open input file");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Header should not be empty");

	if (line != "date | value")
		throw std::runtime_error("Invalid header format");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t pipe = line.find('|');
		if (pipe == std::string::npos || pipe == 0 || pipe == line.length() - 1)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipe - 1);
		if (!checkDate(date))
		{
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}
		std::string valueStr = line.substr(pipe + 2);
		char* end = NULL;
		double value = std::strtod(valueStr.c_str(), &end);
		if (end == valueStr.c_str() || *end != '\0' || value < 0 || value > 1000)
		{
			std::cerr << "Error: invalid value => " << valueStr << std::endl;
			continue;
		}
		double rate = findRate(date);
		if (rate == -1)
		{
			std::cerr << "Error: no exchange rate for date => " << date << std::endl;
			continue;
		}
		std::cout	<< date << " => " << std::left << std::setw(15) << value << " Result Rate = " << value * rate << std::endl;
	}
}