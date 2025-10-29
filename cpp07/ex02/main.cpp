/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:35:35 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/29 12:16:38 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>  // for srand(), rand()
#include <ctime>    // for time()
#include <string>
#include <cstddef>

int main() {
    std::cout << "=== ARRAY CLASS TEMPLATE TESTS ===" << std::endl;
	try
	{
		Array<int> emptyArray; // Default constructor
		std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
		Array<int> numbers(5); // Parameterized constructor
		std::cout << "Size of numbers array: " << numbers.size() << std::endl;
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;	
		std::cout << "Assigning values to numbers array:" << std::endl;
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			numbers[i] = i * 10;
		}
		std::cout << "New contents of numbers array: ";
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
		
		Array<int> copyNumb(numbers); // Copy constructor
		std::cout << "Contents of copied array: ";
		for (unsigned int i = 0; i < copyNumb.size(); i++)
		{
			std::cout << copyNumb[i] << " ";
		}
		std::cout << std::endl;

		copyNumb[0] = -99;
		std::cout << "After modification, contents of copyNumb: ";
		for (unsigned int i = 0; i < copyNumb.size(); i++)
		{
			std::cout << copyNumb[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Original numbers array remains unchanged: ";
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;
		
		Array<int> copy2;
		copy2 = numbers;
		std::cout << "Contents of assigned array copy2: ";
		for (unsigned int i = 0; i < copy2.size(); i++)
		{
			std::cout << copy2[i] << " ";
		}
		std::cout << std::endl;

		const Array<int> constArray(numbers);
		std::cout << "Contents of constArray: ";
		for (unsigned int i = 0; i < constArray.size(); i++)
		{
			std::cout << constArray[i] << " ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}





/* #define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    std::srand(std::time(NULL));
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // SCOPE - Test copy constructor and assignment
    {
        Array<int> tmp = numbers;     // Test assignment operator
        Array<int> test(tmp);         // Test copy constructor
    }

    // Verify that copying worked correctly
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    // Test exception handling - negative index
    try
    {
        numbers[-2] = 0;  // This will be converted to a large unsigned value
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test exception handling - out of bounds index
    try
    {
        numbers[MAX_VAL] = 0;  // Index MAX_VAL is out of bounds (valid indices: 0 to MAX_VAL-1)
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Fill array with new random values
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();  // Fixed: added std:: prefix
    }
    
    delete[] mirror;  // Clean up
    
    std::cout << "All tests completed successfully!" << std::endl;
    
    return 0;
} */