/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:18:43 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/13 21:07:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define NAME "Default"
#define GRADE_TO_SIGN 150
#define GRADE_TO_EXECUTE 150
#define SIGNED false

Form::Form() : name(NAME), isSigned(SIGNED), gradeToSign(GRADE_TO_SIGN), gradeToExecute(GRADE_TO_EXECUTE)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(SIGNED), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Form Parameterized Constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		// name, gradeToSign, and gradeToExecute are const, so we can't assign to them
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form Exception: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form Exception: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}

