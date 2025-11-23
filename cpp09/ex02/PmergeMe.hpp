/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:48:39 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/17 16:06:07 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>

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

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <cmath>
#include <algorithm>

class PmergeMe
{
	public:
		static void mergeInsertSortVector(std::vector<int>& vec, int left, int right, int& comparisons);
		static void mergeInsertSortDeque(std::deque<int>& deq, int left, int right, int& comparisons);

	private:
		static std::vector<int> generateJacobsthalSequence(int n);
		static void binaryInsertVector(std::vector<int>& sorted, int value, int left, int right, int& comparisons);
		static void binaryInsertDeque(std::deque<int>& sorted, int value, int left, int right, int& comparisons);
		static bool compare(int a, int b, int& comparisons);
};