/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:07:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/05 16:50:16 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#

Span::Span() {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSize = other.maxSize;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (numbers.size() < maxSize)
		numbers.push_back(number);
	else
		throw std::length_error("Span is full");
}

unsigned int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (size_t i = 1; i < sortedNumbers.size(); i++)
    {
        unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}