/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:18:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/14 22:45:29 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define NAME "Default"
#define GRADE_TO_SIGN 150
#define GRADE_TO_EXECUTE 150
#define SIGNED false

AForm::AForm() : name(NAME), isSigned(SIGNED), gradeToSign(GRADE_TO_SIGN), gradeToExecute(GRADE_TO_EXECUTE)
{
	std::cout << "Abstract Form Default Constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(SIGNED), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Abstract Form Parameterized Constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Abstract Form Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Abstract Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		// name, gradeToSign, and gradeToExecute are const, so we can't assign to them
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "Abstract Form Destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    action();
}

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Abstract Form Exception: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Abstract Form Exception: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Abstract Form Exception: Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}

