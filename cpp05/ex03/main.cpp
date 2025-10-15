/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 20:43:04 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	std::cout << "\n=== TEST 1 ===" << std::endl;
	std::cout << std::endl;
    try
    {
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm(ROBOTOMY_REQUEST, "Bender");
		
		Bureaucrat Boss("Boss", 1);
		std::cout << Boss << std::endl;

		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);
		delete rrf;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\n=== TEST 2 ===" << std::endl;
	std::cout << std::endl;
    try
    {
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm(SHRUBBERY_CREATION, "Target 2");
		
		Bureaucrat Boss("Boss", 1);
		std::cout << Boss << std::endl;

		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);
		delete rrf;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;

	std::cout << "\n=== TEST 3 ===" << std::endl;
	std::cout << std::endl;
	try
    {
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm(PRESIDENTIAL_PARDON, "Target 3");
		
		Bureaucrat Boss("Boss", 1);
		std::cout << Boss << std::endl;

		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);
		delete rrf;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	
	std::cout << "\n=== TEST 4 ===" << std::endl;
	std::cout << std::endl;
	try
    {
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm(UNKNOWN_FORM, "Bender");
		
		Bureaucrat Boss("Boss", 1);
		std::cout << Boss << std::endl;

		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);
		delete rrf;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}