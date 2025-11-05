/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:06:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/05 17:07:40 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int	main()
{
	try
	{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	
	// should give throw an exception
	sp.addNumber(3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Span	sp2(10001);

	try
	{
		sp2.addNumber(0);
		// should throw an exception, not enough numbers to find a span
		sp2.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{		
		std::vector<int>	manyRandomNumbers(10000);
		std::srand(std::time(0));
		for (size_t i = 0; i < manyRandomNumbers.size(); ++i)
		{
			manyRandomNumbers[i] = std::rand();
		}

		sp2.addRange(manyRandomNumbers.begin(), manyRandomNumbers.end());

		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
		std::cout << std::endl;

		//should throw an exception, max size exceeded
		sp2.addNumber(1001);

	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
