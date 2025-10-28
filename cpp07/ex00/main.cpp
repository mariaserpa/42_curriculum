/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:53:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/28 10:35:52 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	std::cout << "=== FUNCTION TEMPLATES DEMONSTRATION ===" << std::endl;

	// 1. SWAP EXAMPLES
	std::cout << "\n1. SWAP FUNCTION TEMPLATE:" << std::endl;
	
	// The :: operator specifies that you want to use the global version of a function/variable, not one from a namespace like std::
	// Swap integers
	int a = 5, b = 10;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	
	// Swap doubles
	double x = 3.14, y = 2.71;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	// Swap strings
	std::string str1 = "Hello", str2 = "World";
	std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	swap(str1, str2);
	std::cout << "After swap:  str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min(str1, str2) = " << ::min(str1, str2) << std::endl;
	std::cout << "max(str1, str2) = " << ::max(str1, str2) << std::endl;
	return 0;
}