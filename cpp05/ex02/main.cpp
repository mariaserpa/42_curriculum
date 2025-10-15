/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:45 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 19:16:46 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "\n=== TEST SHRUBBERY CREATION FORM ===" << std::endl;
	std::cout << std::endl;
    try
    {
		Bureaucrat Employee("Employee", 150);
		Bureaucrat Boss("Boss", 100);

		std::cout << Employee << std::endl;
		std::cout << Boss << std::endl;
		std::cout << std::endl;
		
		ShrubberyCreationForm Form1("Form1");
		std::cout << Form1 << std::endl;

		Employee.executeForm(Form1); // Should fail, form not signed

		Employee.signForm(Form1);    // Should fail, grade too low
		Boss.signForm(Form1);        // Should succeed
		
		Employee.executeForm(Form1); // Should fail, grade too low
		Boss.executeForm(Form1);     // Should succeed
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\n=== TEST ROBOTOMY REQUEST FORM ===" << std::endl;
	std::cout << std::endl;
    try
    {
		Bureaucrat Employee("Employee", 50);
		Bureaucrat Boss("Boss", 30);

		std::cout << Employee << std::endl;
		std::cout << Boss << std::endl;
		std::cout << std::endl;
		
        RobotomyRequestForm Form2("Form2");
		std::cout << Form2 << std::endl;

		Employee.executeForm(Form2); // Should fail, form not signed

		Employee.signForm(Form2);    // Should fail, grade too low
		Boss.signForm(Form2);        // Should succeed

		Employee.executeForm(Form2); // Should fail, grade too low
		Boss.executeForm(Form2);     // Should succeed
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl;

	std::cout << "\n=== TEST PRESIDENTIAL PARDON FORM ===" << std::endl;
	std::cout << std::endl;
	try
    {
		Bureaucrat Employee("Employee", 33);
		Bureaucrat Boss("Boss", 1);

		std::cout << Employee << std::endl;
		std::cout << Boss << std::endl;
		std::cout << std::endl;

        PresidentialPardonForm Form3("Form3");
		std::cout << Form3 << std::endl;

		Employee.executeForm(Form3); // Should fail, form not signed

		Employee.signForm(Form3);    // Should fail, grade too low
		Boss.signForm(Form3);        // Should succeed

		Employee.executeForm(Form3); // Should fail, grade too low
		Boss.executeForm(Form3);     // Should succeed
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}