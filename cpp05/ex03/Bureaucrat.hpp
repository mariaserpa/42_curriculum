/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:53:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 18:31:30 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(AForm& form);

		const std::string& getName() const; // Return by reference to avoid unnecessary copying
		int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(); //should use virtual because we're overriding the virtual what() method from the base class
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(); //should use virtual because we're overriding the virtual what() method from the base class
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);