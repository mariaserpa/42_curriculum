/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:35:54 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/10 15:19:49 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>

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
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		float f = static_cast<float>(value);
		if (std::isinf(f))
			std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
		else if (f == static_cast<int>(f) && f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
}

static void printDoubleConversion(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		if (value == static_cast<int>(value) && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
			std::cout << std::fixed << std::setprecision(1) << value << std::endl;
		else
			std::cout << value << std::endl;
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
	if (i >= str.length())
		return false;

	bool hasDot = false;
	bool hasE = false;
	bool hasDigitAfterE = false;

	for (; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (hasDot || hasE) return false; // No dot after 'e'
			hasDot = true;
		}
		else if (str[i] == 'e' || str[i] == 'E')
		{
			if (hasE || i == 0 || (i == 1 && (str[0] == '+' || str[0] == '-')))
				return false;
			hasE = true;
			hasDigitAfterE = false;
			// Check for optional sign after 'e'
			if (i + 1 < str.length() && (str[i + 1] == '+' || str[i + 1] == '-'))
			{
				i++; // Skip the sign
				if (i + 1 >= str.length())
					return false; // Must have digits after sign
			}
		}
		else if (std::isdigit(static_cast<unsigned char>(str[i])))
		{
			if (hasE)
				hasDigitAfterE = true; // found a digit after 'e'
		}
		else
				return false;
	}
	// If have 'e', must have at least one digit after it
	if (hasE && !hasDigitAfterE)
		return false;
	return true;
}

static bool isInt(const std::string& str)
{
	return isValidNumber(str) && str.find('.') == std::string::npos && str.find('e') == std::string::npos && str.find('E') == std::string::npos;
}

static bool isFloat(const std::string& str)
{
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;

	std::string number = str.substr(0, str.length() - 1);
	if (!isValidNumber(number))
		return false;

	// Accept if it has a decimal point OR scientific notation
	return (number.find('.') != std::string::npos || number.find('e') != std::string::npos || number.find('E') != std::string::npos);
}

static bool isDouble(const std::string& str)
{
	if (!isValidNumber(str)) return false;  // This might be failing

	return (str.find('.') != std::string::npos || str.find('e') != std::string::npos || str.find('E') != std::string::npos);
}

static bool isPseudoLiteral(const std::string& str)
{
	return (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff");
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
	if (isFloat)
		parseStr = str.substr(0, str.length() - 1); // Remove 'f'

	const char *cstr = parseStr.c_str();
	char *endptr = NULL;
	errno = 0;
	double value = std::strtod(cstr, &endptr);

	// no characters consumed or leftover chars -> invalid input
	if (endptr == cstr || *endptr != '\0')
	{
		printImpossible();
		return;
	}

	// strtod returns +/-inf on overflow and sets errno = ERANGE
	if (errno == ERANGE || std::isinf(value))
	{
		printAllConversions(value);
		return;
	}
	printAllConversions(value);
}


static void handlePseudoLiteral(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
	{
		printImpossible();
		return;
	}
	else if (isPseudoLiteral(str))
		handlePseudoLiteral(str);
	else if (isChar(str))
		handleChar(str);
	else if (isFloat(str))
		handleNumeric(str, true);
	else if (isInt(str) || isDouble(str))
		handleNumeric(str, false);
	else
		printImpossible();
}
