/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:41:25 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 18:27:26 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define NAME "Presidential Pardon Form"
#define GRADE_TO_SIGN 25 //defined by the subject
#define GRADE_TO_EXECUTE 5 //defined by the subject
#define TARGET "PardonTargetDefault"

PresidentialPardonForm::PresidentialPardonForm() : AForm(NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(TARGET)
{
	std::cout << "Presidential Pardon Form Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target)
{
	std::cout << "Presidential Pardon Form Parameterized Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
	std::cout << "Presidential Pardon Form Copy Constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Presidential Pardon Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form Destructor called" << std::endl;
}

void PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}