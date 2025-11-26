/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:47:37 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/26 14:37:44 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream> // for std::ifstream
#include <string> // for std::string
#include <cstdlib> // for std::atof

class BitcoinExchange
{
	private:
		std::string dataFile;
		std::map<std::string, double> dataBase; // container for the database<data, rate>

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &inputFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void processDatabase();
		void processInput();

		double findRate(const std::string &date) const;
};
