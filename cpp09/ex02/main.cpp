/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:47:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/24 21:09:50 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

static int	maxComparisonsFJ(int n) //formula found on https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
{
	int	sum = 0;

	for (int i = 1; i <= n; ++i)
	{
		double value = (3.0 / 4.0) * i;
		double log2value = std::log(value) / std::log(2.0);
		sum += static_cast<int>(std::ceil(log2value));
	}
	return sum;
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
		
		//PmergeMe::setDebug(true);
		std::vector<int> inputVec;
		inputVec.reserve(argc - 1);
		std::deque<int> inputDeque;
		
		for (int i = 1; i < argc; i++)
		{
			int number = std::atoi(argv[i]);
			inputVec.push_back(number);
			inputDeque.push_back(number);
		}
		
		printContainer(inputVec, true);
		
		int countComparisonsVec = 0;
		clock_t vecTimeStart = std::clock();
		PmergeMe::mergeInsertSortVector(inputVec, countComparisonsVec);
		clock_t vecTimeEnd = std::clock();
		
		int countComparisonsDeque = 0;
		clock_t dequeTimeStart = std::clock();
		PmergeMe::mergeInsertSortDeque(inputDeque, countComparisonsDeque);
		clock_t dequeTimeEnd = std::clock();
		
		printContainer(inputVec, false);
		
		double vecTimeMicros = (vecTimeEnd - vecTimeStart) * 1e6 / CLOCKS_PER_SEC;
		double dequeTimeMicros = (dequeTimeEnd - dequeTimeStart) * 1e6 / CLOCKS_PER_SEC;
		
		std::cout << "Time to process a range of " << inputVec.size() 
				<< " elements with std::vector : " << std::fixed 
				<< std::setprecision(2) << vecTimeMicros << " us" << std::endl;
		std::cout << "Time to process a range of " << inputDeque.size() 
				<< " elements with std::deque  : " << std::fixed 
				<< std::setprecision(2) << dequeTimeMicros << " us" << std::endl;
		
		IsSorted(inputVec, "std::vector");
		IsSorted(inputDeque, "std::deque");
		
		std::cout << "Comparisons with std::vector: " << countComparisonsVec << std::endl;
		std::cout << "Comparisons with std::deque : " << countComparisonsDeque << std::endl;
		
		int maxComparisons = maxComparisonsFJ(static_cast<int>(inputVec.size()));
		std::cout << "Theoretical maximum (Ford-Johnson): ~" << maxComparisons << " comparisons" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}