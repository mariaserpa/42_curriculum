/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:35:54 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/23 16:01:19 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// All private constructors and destructor wasn't defined here because no object of this class will be created.
// static_cast can perform conversions between pointers to related classes and keeps intent explicit

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void printCharConversion(double value)
{
	// determines if a numeric (double) value can't be converted to a valid character
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127 || value != static_cast<int>(value))
		std::cout << "char: impossible" << std::endl;
	else if (value >= 32 && value <= 126) // printable ASCII range
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else // non-printable characters
		std::cout << "char: Non displayable" << std::endl;
}

static void printIntConversion(double value)
{
	if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() || value != static_cast<int>(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloatConversion(double value)
{
	std::cout << "float: ";
	if (std::isnan(value)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	} else {
		float f = static_cast<float>(value);
		if (f == static_cast<int>(f) && 
			f >= std::numeric_limits<int>::min() && 
			f <= std::numeric_limits<int>::max()) {
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		} else {
			std::cout << f << "f" << std::endl;
		}
	}
}

static void printDoubleConversion(double value)
{
	std::cout << "double: ";
	if (std::isnan(value)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	} else {
		if (value == static_cast<int>(value) && 
			value >= std::numeric_limits<int>::min() && 
			value <= std::numeric_limits<int>::max()) {
			std::cout << std::fixed << std::setprecision(1) << value << std::endl;
		} else {
			std::cout << value << std::endl;
		}
	}
}

static void printAllConversions(double value)
{
	printCharConversion(value);
	printIntConversion(value);
	printFloatConversion(value);
	printDoubleConversion(value);
}

static bool isChar(const std::string& str)
{
	return str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])) && std::isprint(static_cast<unsigned char>(str[0]));
	//use of static_cast to ensure proper type conversion for character checks
	//use of unsigned char to avoid potential issues with negative char values
	//isprint guarantee only displayable characters (ASCII 32-126) are accepted.
}

static bool isValidNumber(const std::string& str)
{
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	
	if (i >= str.length()) return false; // Just sign
	
	bool hasDot = false;
	for (; i < str.length(); ++i) {
		if (str[i] == '.') {
			if (hasDot) return false; // Multiple dots
			hasDot = true;
		} else if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
			return false;
		}
	}
	return true;
}

static bool isInt(const std::string& str)
{
	return isValidNumber(str) && str.find('.') == std::string::npos;
}

static bool isFloat(const std::string& str)
{
	if (str.length() < 3 || str.back() != 'f') return false;
	
	std::string number = str.substr(0, str.length() - 1);
	return isValidNumber(number) && number.find('.') != std::string::npos;
}

static bool isDouble(const std::string& str)
{
	return isValidNumber(str) && str.find('.') != std::string::npos;
}

static bool isPseudoLiteral(const std::string& str)
{
	return (str == "nan" || str == "+inf" || str == "-inf" || 
			str == "nanf" || str == "+inff" || str == "-inff");
}

static void handleChar(const std::string& str)
{
	char c = str[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void handleNumeric(const std::string& str, bool isFloat = false)
{
	std::string parseStr = str;
	if (isFloat) {
		parseStr = str.substr(0, str.length() - 1); // Remove 'f'
	}
	
	std::istringstream iss(parseStr);
	double value;
	
	if (!(iss >> value) || !iss.eof()) {
		printImpossible();
		return;
	}
	
	// Check float range if it's a float input
	if (isFloat && (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())) {
		printImpossible();
		return;
	}
	
	printAllConversions(value);
}

static void handlePseudoLiteral(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty()) {
		throw std::invalid_argument("Empty string cannot be converted.");
	}
	
	if (isPseudoLiteral(str)) {
		handlePseudoLiteral(str);
	} else if (isChar(str)) {
		handleChar(str);
	} else if (isFloat(str)) {
		handleNumeric(str, true);
	} else if (isInt(str) || isDouble(str)) {
		handleNumeric(str, false);
	} else {
		printImpossible();
	}
}