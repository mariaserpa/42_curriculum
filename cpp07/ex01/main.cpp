/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:20:14 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/28 16:30:27 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

template <typename T>
void increment(T& value)
{
	value++;
}

void uppercaseChar(char& c) {
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

int main()
{
	// Test 1: Integer array
	std::cout << "\n1. Integer Array Tests:" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
	
	// for template functions you need to specify the type <int> when calling it because the compiler cannot automatically
	// deduce the template parameter for function templates when passed as function pointers
	std::cout << "Original: " << std::endl;
	iter(intArray, intSize, print<int>); 
	std::cout << std::endl;

	iter(intArray, intSize, increment<int>);
	
	std::cout << "Incremented:  " << std::endl;
	iter(intArray, intSize, print<int>);
	std::cout << std::endl;

	// Test 2: Character array
	std::cout << "2. Character Array Tests:" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original: " << std::endl;
	iter(charArray, charSize, print<char>);
	std::cout << std::endl;

	iter(charArray, charSize, uppercaseChar); // doesn't need to specify <char> because it is already defined in the function

	std::cout << "Uppercase: " << std::endl;
	iter(charArray, charSize, print<char>);
	std::cout << std::endl;

	return 0;
}