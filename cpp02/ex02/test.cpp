/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:07:20 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/05 14:36:53 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void test()
{
    Fixed a(10);
    Fixed b(5);
    Fixed c(10);

    std::cout << "\nTesting Comparison Operators:" << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;

    std::cout << std::endl;


    std::cout << "Testing Arithmetic Operators:" << std::endl;

    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    std::cout << std::endl;


    std::cout << "Testing Increment/Decrement Operators:" << std::endl;

    std::cout << "Initial value: " << a << std::endl;

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << std::endl;

    const Fixed d(20);
    const Fixed e(15);

	std::cout << std::endl;
	
    std::cout << "Testing Min/Max Functions:" << std::endl;

    std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;
    std::cout << "Min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "Max(d, e): " << Fixed::max(d, e) << std::endl;

    std::cout << std::endl;
}

