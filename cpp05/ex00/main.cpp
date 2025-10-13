/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/13 20:13:58 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// Case of invalid grade (too high)
	try
	{
		Bureaucrat bureaucrat("Bureaucrat A", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	// Case of invalid grade (too low)
	try
	{
		Bureaucrat bureaucrat("Bureaucrat B", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// Valid case
	try
	{
		Bureaucrat bureaucrat("Bureaucrat C", 75);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << "After increment: " << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << "After decrement: " << bureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}