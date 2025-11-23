/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:48:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/17 16:06:07 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::generateJacobsthalSequence(int n) // Formula: J(n) = J(n-1) + 2*J(n-2)
{
	std::vector<int> jacobsthal;
	if (n <= 0) return jacobsthal;

	jacobsthal.push_back(1);
	if (n == 1) return jacobsthal;
	
	jacobsthal.push_back(1);
	if (n == 1) return jacobsthal;
	
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

bool PmergeMe::compare(int a, int b, int& comparisons)
{
	comparisons++;
	return a < b;
}

// Binary insertion with proper bounds checking
void PmergeMe::binaryInsertVector(std::vector<int>& sorted, int value, int left, int right, int& comparisons)
{
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (compare(sorted[mid], value, comparisons))
			left = mid + 1;
		else
			right = mid;
	}
	sorted.insert(sorted.begin() + left, value);
}

void PmergeMe::binaryInsertDeque(std::deque<int>& sorted, int value, int left, int right, int& comparisons)
{
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (compare(sorted[mid], value, comparisons))
			left = mid + 1;
		else
			right = mid;
	}
	sorted.insert(sorted.begin() + left, value);
}

// True Ford-Johnson algorithm for vector with recursion
void PmergeMe::mergeInsertSortVector(std::vector<int>& vec, int left, int right, int& comparisons)
{
	int size = right - left;
	if (size <= 1) return;
	
	// Phase 1: Pairwise comparison and grouping
	std::vector<int> larger, smaller;
	int straggler = -1;
	
	// Group into pairs and compare
	for (int i = left; i < right - 1; i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		
		if (compare(b, a, comparisons)) // b < a
		{
			larger.push_back(a);	// a is larger
			smaller.push_back(b);   // b is smaller
		}
		else
		{
			larger.push_back(b);	// b is larger
			smaller.push_back(a);   // a is smaller
		}
	}
	
	// Handle odd element (straggler)
	if (size % 2 == 1)
		straggler = vec[right - 1];
	
	// Phase 2: Recursively sort the larger elements (KEY FIX!)
	if (larger.size() > 1)
	{
		mergeInsertSortVector(larger, 0, static_cast<int>(larger.size()), comparisons);
	}
	
	// Phase 3: Build main chain and insert smaller elements
	std::vector<int> main = larger;  // Main chain starts with sorted larger elements
	
	if (!smaller.empty())
	{
		// Insert first smaller element at the beginning (it's guaranteed to be smallest)
		main.insert(main.begin(), smaller[0]);
		
		// Generate Jacobsthal sequence for optimal insertion order
		std::vector<int> jacobsthal = generateJacobsthalSequence(static_cast<int>(smaller.size()));
		std::vector<bool> inserted(smaller.size(), false);
		inserted[0] = true; // First element already inserted
		
		// Insert according to Jacobsthal sequence
		for (size_t j = 0; j < jacobsthal.size(); ++j)
		{
			int jacobsthal_num = jacobsthal[j];
			
			// Insert in reverse order within each Jacobsthal group
			int start = (j == 0) ? jacobsthal_num : jacobsthal_num;
			int end = (j == 0) ? 2 : jacobsthal[j-1] + 1;
			
			for (int idx = start - 1; idx >= end - 1 && idx >= 1; --idx)
			{
				if (idx < static_cast<int>(smaller.size()) && !inserted[idx])
				{
					// Find the corresponding larger element's position in main
					int bound_pos = -1;
					for (size_t k = 0; k < main.size(); ++k)
					{
						if (main[k] == larger[idx])
						{
							bound_pos = static_cast<int>(k);
							break;
						}
					}
					
					// Insert with bounded binary search
					int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;
					binaryInsertVector(main, smaller[idx], 0, search_limit, comparisons);
					inserted[idx] = true;
				}
			}
		}
		
		// Insert any remaining elements in reverse order
		for (int i = static_cast<int>(smaller.size()) - 1; i >= 1; --i)
		{
			if (!inserted[i])
			{
				// Find bound position
				int bound_pos = -1;
				for (size_t k = 0; k < main.size(); ++k)
				{
					if (main[k] == larger[i])
					{
						bound_pos = static_cast<int>(k);
						break;
					}
				}
				
				int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;
				binaryInsertVector(main, smaller[i], 0, search_limit, comparisons);
			}
		}
	}
	
	// Insert straggler if it exists
	if (straggler != -1)
	{
		binaryInsertVector(main, straggler, 0, static_cast<int>(main.size()), comparisons);
	}
	
	// Copy result back to original vector
	for (size_t i = 0; i < main.size(); ++i)
	{
		vec[left + i] = main[i];
	}
}

// True Ford-Johnson algorithm for deque with recursion
void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq, int left, int right, int& comparisons)
{
	int size = right - left;
	if (size <= 1) return;
	
	// Phase 1: Pairwise comparison and grouping
	std::deque<int> larger, smaller;
	int straggler = -1;
	
	// Group into pairs and compare
	for (int i = left; i < right - 1; i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		
		if (compare(b, a, comparisons)) // b < a
		{
			larger.push_back(a);	// a is larger
			smaller.push_back(b);   // b is smaller
		}
		else
		{
			larger.push_back(b);	// b is larger
			smaller.push_back(a);   // a is smaller
		}
	}
	
	// Handle odd element (straggler)
	if (size % 2 == 1)
		straggler = deq[right - 1];
	
	// Phase 2: Recursively sort the larger elements (KEY FIX!)
	if (larger.size() > 1)
	{
		mergeInsertSortDeque(larger, 0, static_cast<int>(larger.size()), comparisons);
	}
	
	// Phase 3: Build main chain and insert smaller elements
	std::deque<int> main = larger;  // Main chain starts with sorted larger elements
	
	if (!smaller.empty())
	{
		// Insert first smaller element at the beginning
		main.push_front(smaller[0]);
		
		// Generate Jacobsthal sequence for optimal insertion order
		std::vector<int> jacobsthal = generateJacobsthalSequence(static_cast<int>(smaller.size()));
		std::vector<bool> inserted(smaller.size(), false);
		inserted[0] = true; // First element already inserted
		
		// Insert according to Jacobsthal sequence
		for (size_t j = 0; j < jacobsthal.size(); ++j)
		{
			int jacobsthal_num = jacobsthal[j];
			
			// Insert in reverse order within each Jacobsthal group
			int start = (j == 0) ? jacobsthal_num : jacobsthal_num;
			int end = (j == 0) ? 2 : jacobsthal[j-1] + 1;
			
			for (int idx = start - 1; idx >= end - 1 && idx >= 1; --idx)
			{
				if (idx < static_cast<int>(smaller.size()) && !inserted[idx])
				{
					// Find the corresponding larger element's position in main
					int bound_pos = -1;
					for (size_t k = 0; k < main.size(); ++k)
					{
						if (main[k] == larger[idx])
						{
							bound_pos = static_cast<int>(k);
							break;
						}
					}
					
					// Insert with bounded binary search
					int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;
					binaryInsertDeque(main, smaller[idx], 0, search_limit, comparisons);
					inserted[idx] = true;
				}
			}
		}
		
		// Insert any remaining elements in reverse order
		for (int i = static_cast<int>(smaller.size()) - 1; i >= 1; --i)
		{
			if (!inserted[i])
			{
				// Find bound position
				int bound_pos = -1;
				for (size_t k = 0; k < main.size(); ++k)
				{
					if (main[k] == larger[i])
					{
						bound_pos = static_cast<int>(k);
						break;
					}
				}
				
				int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;
				binaryInsertDeque(main, smaller[i], 0, search_limit, comparisons);
			}
		}
	}
	
	// Insert straggler if it exists
	if (straggler != -1)
	{
		binaryInsertDeque(main, straggler, 0, static_cast<int>(main.size()), comparisons);
	}
	
	// Copy result back to original deque
	for (size_t i = 0; i < main.size(); ++i)
	{
		deq[left + i] = main[i];
	}
}