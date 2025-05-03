/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:42:09 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/02 15:57:10 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

static void setStringField(std::string &field, const std::string prompt)
{
	std::string input;

	while(true)
	{
		std::cout << "ADD " << prompt;
		std::getline(std::cin, input);
		
		if (std::cin.eof())
		{
			std::cout << "\nExiting due to EOF." << std::endl;
			exit(0);
		}
		if (input.empty())
		{
			std::cout << "Field cannot be empty. Please try again." << std::endl;
			continue;
		}
		field = input;
		return ;
	}
}

static bool checkPhoneNumber(const std::string &phoneNumber)
{
	size_t i;
	char c;
	for (i = 0; i < phoneNumber.length(); ++i)
	{
		c = phoneNumber[i];
		if (!std::isdigit(static_cast<unsigned int>(c)) && 
			c != ' ' && c != '-' && c != '+' && c != '(' && c != ')')
			return true;
	}
	return false;
}

static void setNumberField(std::string &field, const std::string prompt)
{
	std::string input;

	while(true)
	{
		std::cout << "ADD " << prompt;
		std::getline(std::cin, input);
		
		if (std::cin.eof())
		{
			std::cout << "\nExiting due to EOF." << std::endl;
			exit(0);
		}
		if (input.empty())
		{
			std::cout << "Field cannot be empty. Please try again." << std::endl;
			continue;
		}
		if (checkPhoneNumber(input))
		{
			std::cout << "Phone number must be numeric. Please try again." << std::endl;
			continue;
		}
		field = input;
		return ;
	}
}

void Contact::setContact(void)
{
	setStringField(this->FirstName, "First Name: ");
	setStringField(this->LastName, "Last Name: ");
	setStringField(this->NickName, "Nick Name: ");
	setNumberField(this->PhoneNumber, "Phone Number: ");
	setStringField(this->DarkestSecret, "Darkest Secret: ");
	std::cout << "Contact added successfully!" << std::endl;
}

static void truncateAlign(const std::string &str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::displayContact(int index) const
{
	std::string indexStr = std::to_string(index + 1);

	std::cout << "|";
	truncateAlign(indexStr);
	std::cout << "|";
	truncateAlign(this->FirstName);
	std::cout << "|";
	truncateAlign(this->LastName);
	std::cout << "|";
	truncateAlign(this->NickName);
	std::cout << "|";
	std::cout << std::endl;
}

void Contact::displayContactDetails(void) const
{
	std::cout << "First Name: " << this->FirstName << std::endl;
	std::cout << "Last Name: " << this->LastName << std::endl;
	std::cout << "Nick Name: " << this->NickName << std::endl;
	std::cout << "Phone Number: " << this->PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->DarkestSecret << std::endl;
}