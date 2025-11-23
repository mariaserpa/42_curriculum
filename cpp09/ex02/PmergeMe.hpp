/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:48:39 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/23 21:14:54 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cmath>
#include <algorithm>
#include <ctime> 
#include <cstdlib>


class PmergeMe
{
	public:
		static void mergeInsertSortVector(std::vector<int>& vec, int left, int right, int& comparisons);
		static void mergeInsertSortDeque(std::deque<int>& deq, int left, int right, int& comparisons);

		template<typename Container>
		static Container generateJacobsthalSequence(int n);

	private:
		static void binaryInsertVector(std::vector<int>& sorted, int value, int left, int right, int& comparisons);
		static void binaryInsertDeque(std::deque<int>& sorted, int value, int left, int right, int& comparisons);
		static bool compare(int a, int b, int& comparisons);

		// --- NEW helpers for the vector version ---
		static void pairAndGroupVector(const std::vector<int>& vec, int left, int right, std::vector<int>& larger, 
										std::vector<int>& smaller, int& straggler, int& comparisons);

		static void reorderPairsVector(const std::vector<int>& largerSorted, std::vector<int>& largerOriginal,
										std::vector<int>& smaller);

		static void buildMainChainVector(std::vector<int>& main, const std::vector<int>& smaller,
										const std::vector<int>& largerOriginal, int straggler, int& comparisons);
};



template<typename Container>
Container PmergeMe::generateJacobsthalSequence(int n) // Formula: J(n) = J(n-1) + 2*J(n-2)
{
	Container jacobsthal;
	if (n <= 0) return jacobsthal;

	jacobsthal.push_back(1);
	if (n == 1) return jacobsthal;
	
	jacobsthal.push_back(1);
	
	int prev2 = 1, prev1 = 1;
	while (true)
	{
		int next = prev1 + 2 * prev2;
		if (next > n) break;
		jacobsthal.push_back(next);
		prev2 = prev1;
		prev1 = next;
	}
	return jacobsthal;
}


template<typename Container>
void printContainer(const Container& container, const std::string& containerName, bool is_before)
{
	if (is_before)
		std::cout << containerName << " before:\t";
	else
		std::cout << containerName << " after:\t";
	
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}