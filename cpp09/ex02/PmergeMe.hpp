/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:48:39 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/16 21:15:34 by mrabelo-         ###   ########.fr       */
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

class PmergeMe
{
	private: //constructors and destructor in private to prevent instantiation
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

	public:
		static void mergeInsertSortVector(std::vector<int> &vec, int left, int right);
		static void mergeInsertSortDeque(std::deque<int> &deq, int left, int right);
};