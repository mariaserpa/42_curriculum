/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:53:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/28 11:20:33 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	std::cout << "=== FUNCTION TEMPLATES DEMONSTRATION ===" << std::endl;

	// 1. SWAP EXAMPLES
	std::cout << "\n1. SWAP FUNCTION TEMPLATE:" << std::endl;
	
	// The :: operator specifies that you want to use the global version of a function/variable, not one from a namespace like std::
	// Swap integers
	int e = 5, f = 10;
	std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "After swap:  e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

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
	
	
	std::cout << "MAIN from the subject" << std::endl;
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}