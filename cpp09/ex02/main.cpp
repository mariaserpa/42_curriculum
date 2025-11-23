/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:47:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/17 16:00:46 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

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
		double	value = (3.0 / 4.0) * i;
		sum += static_cast<int>(ceil(log2(value)));
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
		std::vector<int> inputVec;
		inputVec.reserve(argc - 1); //reserve space to avoid reallocations. Allocates memory but doesn't construct elements until push_back()
		std::deque<int> inputDeque; //reserve doesn't exist for deque but it's less of a concern due to its structure
		for (int i = 1; i < argc; i++)
		{
			int number = std::atoi(argv[i]);
			inputVec.push_back(number);
			inputDeque.push_back(number);
		}
		
		int countComparisonsVec = 0;
		int countComparisonsDeque = 0;

		printContainer(inputVec, "Vector", true);
		double vecTimeStart = static_cast<double>(std::clock());
		PmergeMe::mergeInsertSortVector(inputVec, 0, static_cast<int>(inputVec.size()), countComparisonsVec);
		double vecTimeEnd = static_cast<double>(std::clock());
		printContainer(inputVec, "Vector", false);
		
		printContainer(inputDeque, "Deque", true);
		double dequeTimeStart = static_cast<double>(std::clock());
		PmergeMe::mergeInsertSortDeque(inputDeque, 0, static_cast<int>(inputDeque.size()), countComparisonsDeque);
		double dequeTimeEnd = static_cast<double>(std::clock());
		printContainer(inputDeque, "Deque", false);

		double vecTimeMicros = vecTimeEnd - vecTimeStart;
		double dequeTimeMicros = dequeTimeEnd - dequeTimeStart;

		std::cout << "Time to process a range of " << inputVec.size() 
					<< " elements with std::vector : " << vecTimeMicros << " us" << std::endl;
		std::cout << "Time to process a range of " << inputDeque.size() 
					<< " elements with std::deque  : " << dequeTimeMicros << " us" << std::endl;

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