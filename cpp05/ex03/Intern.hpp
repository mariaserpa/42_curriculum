/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:36:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/15 20:25:17 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define SHRUBBERY_CREATION "shrubbery creation"
#define ROBOTOMY_REQUEST "robotomy request"
#define PRESIDENTIAL_PARDON "presidential pardon"
#define UNKNOWN_FORM "unknown form"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};