/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:47:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/16 21:35:11 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque> 
#include <sstream>

static void validateArgs(int argc, char**argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		long number;  // Use long instead of int
		if (!(ss >> number) || !(ss.eof()))
			throw std::runtime_error("Invalid input '" + std::string(argv[i]) + "'. Not a valid integer.");
		if (number < 0)
			throw std::runtime_error("Invalid input '" + std::string(argv[i]) + "'. Only non-negative integers are allowed.");
		if (number > INT_MAX)
			throw std::runtime_error("Invalid input '" + std::string(argv[i]) + "'. Value exceeds INT_MAX.");
	}
}

int main(int argc, char**argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input numbers provided." << std::endl;
		return 1;
	}
	try 
	{
		validateArgs(argc, argv);
		std::vector<int> inputVec;
		inputVec.reserve(argc - 1); //reserve space to avoid reallocations. Allocates memory but doesn't construct elements until push_back()
		std::deque<int> inputDeque; //reserve doesn't exist for deque but it's less of a concern due to its structure
		for (int i = 1; i < argc; i++)
		{
			inputVec.push_back(std::atoi(argv[i]));
			inputDeque.push_back(std::atoi(argv[i]));
		}
		
		int countComparisonsVec = 0;
		int countComparisonsDeque = 0;

		printContainer(inputVec, "Vector", true);
		double vecTimeStart = static_cast<double>(std::clock());
		//PmergeMe::mergeInsertSortVector
		double vecTimeEnd = static_cast<double>(std::clock());
		printContainer(inputVec, "Vector", false);
		
		printContainer(inputDeque, "Deque", true);
		double dequeTimeStart = static_cast<double>(std::clock());
		//PmergeMe::mergeInsertSortDeque
		double dequeTimeEnd = static_cast<double>(std::clock());
		printContainer(inputDeque, "Deque", false);

		std::cout << "Time taken for vector: " << (vecTimeEnd - vecTimeStart) / (CLOCKS_PER_SEC / 1000000.0) << " us" << std::endl;
		std::cout << "Time taken for deque: " << (dequeTimeEnd - dequeTimeStart) / (CLOCKS_PER_SEC / 1000000.0) << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}