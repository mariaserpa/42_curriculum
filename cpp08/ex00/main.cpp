/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:06:35 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/13 16:03:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>


int main()
{
    std::cout << "=== Testing easyfind with std::vector ===" << std::endl;

    // Test with vector (container type)
    // push_back is used to add elements to the vector (member function of std::vector)
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(-20);
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(50); // duplicate value

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value 42 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try //should throw exception
    {
        std::vector<int>::iterator it = easyfind(vec, 999);
        std::cout << "Found value 999 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing easyfind with std::list ===" << std::endl;

    // Test with list (another container type)
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found value 20 at position: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try //should throw exception
    {
        std::list<int>::iterator it = easyfind(lst, 50);
        std::cout << "Found value 50 at position: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
