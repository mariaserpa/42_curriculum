/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:35:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/23 15:28:58 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string> // for std::string
#include <iostream> // for std::cout, std::endl
#include <limits> // for std::numeric_limits
#include <sstream> // for std::istringstream
#include <iomanip> // for std::setprecision
#include <cctype> // for std::isprint
#include <cmath> // for std::isnan, std::isinf

class ScalarConverter
{
	private: // Private constructor and destructor to prevent instantiation
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& literal);
};