/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/13 22:54:36 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	std::cout << "\n=== WRONG FORM CONSTRUCTION TESTS ===" << std::endl;
	std::cout << std::endl;
	// Case of invalid form grade (too high)
    try
    {
        Form form("WrongFormHigh", 0, 50);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
	
    // Case of invalid form grade (too low)
    try
    {
        Form form("WrongFormLow", 50, 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	
	std::cout << "\n=== CORRECT FORM CONSTRUCTION AND SIGNING TESTS ===" << std::endl;
	std::cout << std::endl;
	// Valid case
	try
    {
        // Create valid form and bureaucrats
        Bureaucrat highRank("CEO", 1);
        Bureaucrat midRank("Manager", 50);
        Bureaucrat lowRank("Intern", 100);
        
        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;
        
		// Create first form
		std::cout << std::endl;
        Form form("Contract Form", 50, 25);
        std::cout << "\n" << form << std::endl;
        
        // Test successful signing
        std::cout << "High rank bureaucrat signing form..." << std::endl;
        form.beSigned(highRank);
        std::cout << "After signing: " << form << std::endl;
        
        // Create another form for more tests
		std::cout << std::endl;
        Form form2("License Form", 75, 50);
        std::cout << "\n" << form2 << std::endl;
        
        // Test successful signing with exact grade
        std::cout << "Mid rank bureaucrat signing form2..." << std::endl;
        form2.beSigned(midRank);
        std::cout << "After signing: " << form2 << std::endl;
		std::cout << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== SIGNING FAILURE TEST ===" << std::endl;
	std::cout << std::endl;
    
    try
    {
        Form form3("Executive Order", 10, 5);
        Bureaucrat lowRank("Junior", 150);
        
        std::cout << form3 << std::endl;
        std::cout << lowRank << std::endl;
        
        std::cout << "Low rank bureaucrat trying to sign executive form..." << std::endl;
        form3.beSigned(lowRank);  // This should throw exception
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}