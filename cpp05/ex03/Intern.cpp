/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:26 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 20:27:49 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern Copy Assignment Operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

static AForm* createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	if (formName.empty())
    {
        std::cout << "Intern cannot create a form with an empty name." << std::endl;
        throw UnknownFormException();
    }
    
    const char* names[] = {
        SHRUBBERY_CREATION,
        ROBOTOMY_REQUEST,
        PRESIDENTIAL_PARDON
    };
    
    AForm* (*creators[])(const std::string&) = {
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };
    
    const size_t numForms = sizeof(names) / sizeof(names[0]);
    
    for (size_t i = 0; i < numForms; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    
    std::cout << "Intern cannot create " << formName << " form because it doesn't exist" << std::endl;
    throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form type";
}