/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:48:41 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/24 21:13:03 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool PmergeMe::_debug = false;

void PmergeMe::setDebug(bool enabled)
{
	_debug = enabled;
}

void PmergeMe::debugPrintVector(const std::string& label, const std::vector<int>& v, int comparisons)
{
	if (!_debug)
		return;

	std::cout << "[DEBUG] " << label << " | comparisons = " << comparisons << " | values: ";

	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

bool PmergeMe::compare(int a, int b, int& comparisons)
{
	comparisons++;
	if (_debug)
	{
		std::cout << "[DEBUG] compare(" << a << ", " << b << ") -> "
				<< (a < b ? "true" : "false")
				<< " | total comparisons = " << comparisons << std::endl;
	}
	return a < b;
}

void PmergeMe::binaryInsertVector(std::vector<int>& sorted, int value, int right, int& comparisons)
{
	int left = 0;
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

void PmergeMe::pairAndGroupVector(const std::vector<int>& vec, std::vector<int>& larger, std::vector<int>& smaller,
									int& straggler, int& comparisons)
{
	int size = static_cast<int>(vec.size());
	straggler = -1;

	for (int i = 0; i < size - 1; i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];

		if (compare(b, a, comparisons)) // b < a
		{
			larger.push_back(a);  // a is larger
			smaller.push_back(b); // b is smaller
		}
		else
		{
			larger.push_back(b);  // b is larger
			smaller.push_back(a); // a is smaller
		}
	}
	if (size % 2 == 1)
		straggler = vec[size - 1];
}

void PmergeMe::reorderPairsVector(const std::vector<int>& largerSorted, std::vector<int>& largerOriginal, 
									std::vector<int>& smaller)
{
	std::vector<bool> used(largerOriginal.size(), false);
	std::vector<int> sortedSmaller;
	std::vector<int> sortedLargerOriginal;

	sortedSmaller.reserve(smaller.size());
	sortedLargerOriginal.reserve(largerOriginal.size());

	for (size_t i = 0; i < largerSorted.size(); ++i)
	{
		int a_val = largerSorted[i];

		for (size_t j = 0; j < largerOriginal.size(); ++j)
		{
			if (!used[j] && largerOriginal[j] == a_val)
			{
				used[j] = true;
				sortedLargerOriginal.push_back(a_val);
				sortedSmaller.push_back(smaller[j]);
				break;
			}
		}
	}

	largerOriginal.swap(sortedLargerOriginal);
	smaller.swap(sortedSmaller);
}

void PmergeMe::buildMainChainVector(std::vector<int>& main, const std::vector<int>& smaller, 
									const std::vector<int>& largerOriginal, int straggler, int& comparisons)
{
	if (!smaller.empty())
	{
		// Insert first smaller element at the beginning
		main.insert(main.begin(), smaller[0]);
		if (_debug)
		{
			std::cout << "[DEBUG] Insert first smaller (vector): " << smaller[0] << std::endl;
			debugPrintVector("Vector main after first smaller", main, comparisons);
		}

		std::vector<int> jacobsthal = PmergeMe::generateJacobsthalSequence<std::vector<int> >(static_cast<int>(smaller.size()));
		std::vector<bool> inserted(smaller.size(), false);
		inserted[0] = true;

		for (size_t j = 0; j < jacobsthal.size(); ++j)
		{
			int jacobsthal_num = jacobsthal[j];
			int start = jacobsthal_num;
			int end = (j == 0) ? 2 : jacobsthal[j - 1] + 1;

			for (int idx = start - 1; idx >= end - 1 && idx >= 1; --idx)
			{
				if (idx < static_cast<int>(smaller.size()) && !inserted[idx])
				{
					int bound_pos = -1;
					for (size_t k = 0; k < main.size(); ++k)
					{
						if (main[k] == largerOriginal[idx])
						{
							bound_pos = static_cast<int>(k);
							break;
						}
					}

					int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;

					binaryInsertVector(main, smaller[idx], search_limit, comparisons);
					inserted[idx] = true;
					if (_debug)
					{
						std::cout << "[DEBUG] Insert smaller[" << idx << "] = "
								<< smaller[idx] << " (vector, Jacobsthal step)" << std::endl;
						debugPrintVector("Vector main after insertion", main, comparisons);
					}
				}
			}
		}

		for (int i = static_cast<int>(smaller.size()) - 1; i >= 1; --i)
		{
			if (!inserted[i])
			{
				int bound_pos = -1;
				for (size_t k = 0; k < main.size(); ++k)
				{
					if (main[k] == largerOriginal[i])
					{
						bound_pos = static_cast<int>(k);
						break;
					}
				}

				int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;

				binaryInsertVector(main, smaller[i], search_limit, comparisons);
				if (_debug)
				{
					std::cout << "[DEBUG] Insert remaining smaller[" << i << "] = "
							<< smaller[i] << " (vector, remaining)" << std::endl;
					debugPrintVector("Vector main after insertion", main, comparisons);
				}
			}
		}
	}

	if (straggler != -1)
		binaryInsertVector(main, straggler, static_cast<int>(main.size()), comparisons);
	if (_debug)
	{
		std::cout << "[DEBUG] Insert straggler (vector): " << straggler << std::endl;
		debugPrintVector("Vector main after straggler", main, comparisons);
	}
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec, int& comparisons)
{
	int size = static_cast<int>(vec.size());
	if (size <= 1)
		return;

	if (_debug)
		debugPrintVector("mergeInsertSortVector - input", vec, comparisons);

	std::vector<int> larger;
	std::vector<int> smaller;
	int straggler = -1;

	pairAndGroupVector(vec, larger, smaller, straggler, comparisons);
	
	if (_debug)
	{
		debugPrintVector("Vector pairing - larger", larger, comparisons);
		debugPrintVector("Vector pairing - smaller", smaller, comparisons);
		if (straggler != -1)
			std::cout << "[DEBUG] Vector pairing - straggler: " << straggler << std::endl;
	}
	
	std::vector<int> largerOriginal = larger;

	// recursively sort the larger elements
	if (larger.size() > 1)
		PmergeMe::mergeInsertSortVector(larger, comparisons);

	if (_debug)
		debugPrintVector("Vector after recursive sort of larger", larger, comparisons);

	// Reorder pairs according to sorted 'larger'
	reorderPairsVector(larger, largerOriginal, smaller);

	if (_debug)
	{
		debugPrintVector("Vector after reorderPairs - largerOriginal", largerOriginal, comparisons);
		debugPrintVector("Vector after reorderPairs - smaller", smaller, comparisons);
	}

	std::vector<int> main = larger; // 'larger' is already sorted
	buildMainChainVector(main, smaller, largerOriginal, straggler, comparisons);

	if (_debug)
		debugPrintVector("Vector main chain after buildMainChainVector", main, comparisons);

	for (size_t i = 0; i < main.size(); ++i)
		vec[i] = main[i];
}

// deque algorithm

void PmergeMe::binaryInsertDeque(std::deque<int>& sorted, int value, int right, int& comparisons)
{
	int left = 0;
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

void PmergeMe::pairAndGroupDeque(const std::deque<int>& deq, std::deque<int>& larger, std::deque<int>& smaller,
									int& straggler, int& comparisons)
{
	int size = static_cast<int>(deq.size());
	straggler = -1;

	for (int i = 0; i < size - 1; i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];

		if (compare(b, a, comparisons)) // b < a
		{
			larger.push_back(a);
			smaller.push_back(b);
		}
		else
		{
			larger.push_back(b);
			smaller.push_back(a);
		}
	}

	if (size % 2 == 1)
		straggler = deq[size - 1];
}

void PmergeMe::reorderPairsDeque(const std::deque<int>& largerSorted, std::deque<int>& largerOriginal,
									std::deque<int>& smaller)
{
	std::deque<bool> used(largerOriginal.size(), false);
	std::deque<int> sortedSmaller;
	std::deque<int> sortedLargerOriginal;

	for (size_t i = 0; i < largerSorted.size(); ++i)
	{
		int a_val = largerSorted[i];

		for (size_t j = 0; j < largerOriginal.size(); ++j)
		{
			if (!used[j] && largerOriginal[j] == a_val)
			{
				used[j] = true;
				sortedLargerOriginal.push_back(a_val);
				sortedSmaller.push_back(smaller[j]);
				break;
			}
		}
	}

	largerOriginal.swap(sortedLargerOriginal);
	smaller.swap(sortedSmaller);
}

void PmergeMe::buildMainChainDeque(std::deque<int>& main, const std::deque<int>& smaller, 
									const std::deque<int>& largerOriginal, int straggler, int& comparisons)
{
	if (!smaller.empty())
	{
		// Insert first smaller element at the beginning (paired with smallest larger)
		main.push_front(smaller[0]);

		std::deque<int> jacobsthal = PmergeMe::generateJacobsthalSequence<std::deque<int> >(static_cast<int>(smaller.size()));
		std::deque<bool> inserted(smaller.size(), false);
		inserted[0] = true;

		for (size_t j = 0; j < jacobsthal.size(); ++j)
		{
			int jacobsthal_num = jacobsthal[j];
			int start = jacobsthal_num;
			int end = (j == 0) ? 2 : jacobsthal[j - 1] + 1;

			for (int idx = start - 1; idx >= end - 1 && idx >= 1; --idx)
			{
				if (idx < static_cast<int>(smaller.size()) && !inserted[idx])
				{
					int bound_pos = -1;
					for (size_t k = 0; k < main.size(); ++k)
					{
						if (main[k] == largerOriginal[idx])
						{
							bound_pos = static_cast<int>(k);
							break;
						}
					}

					int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;

					binaryInsertDeque(main, smaller[idx], search_limit, comparisons);
					inserted[idx] = true;
				}
			}
		}

		for (int i = static_cast<int>(smaller.size()) - 1; i >= 1; --i)
		{
			if (!inserted[i])
			{
				int bound_pos = -1;
				for (size_t k = 0; k < main.size(); ++k)
				{
					if (main[k] == largerOriginal[i])
					{
						bound_pos = static_cast<int>(k);
						break;
					}
				}

				int search_limit = (bound_pos == -1) ? static_cast<int>(main.size()) : bound_pos;

				binaryInsertDeque(main, smaller[i], search_limit, comparisons);
			}
		}
	}

	if (straggler != -1)
		binaryInsertDeque(main, straggler, static_cast<int>(main.size()), comparisons);
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq, int& comparisons)
{
	int size = static_cast<int>(deq.size());
	if (size <= 1)
		return;

	std::deque<int> larger;
	std::deque<int> smaller;
	int straggler = -1;

	pairAndGroupDeque(deq, larger, smaller, straggler, comparisons);

	std::deque<int> largerOriginal = larger;

	if (larger.size() > 1)
		PmergeMe::mergeInsertSortDeque(larger, comparisons);

	reorderPairsDeque(larger, largerOriginal, smaller);

	std::deque<int> main = larger;
	buildMainChainDeque(main, smaller, largerOriginal, straggler, comparisons);

	for (size_t i = 0; i < main.size(); ++i)
		deq[i] = main[i];
}
