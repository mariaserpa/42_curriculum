/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:06:44 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/13 16:13:34 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>
#include <iostream>

class Span
{
	private:
		unsigned int		maxSize; // maximum capacity
		std::vector<int>	numbers; // container to hold the numbers
		//vector fits here because Span needs sequence of ints
	public:
		Span();
		explicit Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		//Iterators are used to access and iterate by "pointing" to them.
		template<typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if ((numbers.size() + std::distance(begin, end)) > maxSize) //check the if exceeds max size
				throw std::length_error("Maximum size exceeded");
			numbers.insert(numbers.end(), begin, end);
		}
};
