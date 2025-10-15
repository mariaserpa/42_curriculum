/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:41:30 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 18:17:38 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#define NAME "Robotomy Request Form"
#define GRADE_TO_SIGN 72 //defined by the subject
#define GRADE_TO_EXECUTE 45 //defined by the subject
#define TARGET "RobotomyTargetDefault"

RobotomyRequestForm::RobotomyRequestForm() : AForm(NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(TARGET)
{
	std::cout << "Robotomy Request Form Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target)
{
	std::cout << "Robotomy Request Form Parameterized Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
	std::cout << "Robotomy Request Form Copy Constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Robotomy Request Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form Destructor called" << std::endl;
}

void RobotomyRequestForm::action() const
{
	std::cout << "Drilling noises..." << std::endl;
	std::srand(std::time(0));
	int randomValue = std::rand() % 2;
	
	// Simulate a 50% chance of success
	if (randomValue == 0)
	{
		std::cout << target << " has been robotomized successfully!" << std::endl;
		return;
	}
	else
	{
		std::cout << "The robotomy on " << target << " failed." << std::endl;
	}
}