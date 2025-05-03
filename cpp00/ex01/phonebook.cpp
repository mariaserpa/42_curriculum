/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:42:37 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/02 15:57:05 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::addContact()
{
	int index;

	index = this->count % 8;
	this->contact[index].setContact();
	this->count++;
}

static bool isOnlyNumeric(const std::string &input)
{
	return std::all_of(input.begin(), input.end(), ::isdigit);
}

static int getIndex()
{
	std::string input;
	int index;

	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\nExiting due to EOF." << std::endl;
		exit(0);
	}
	if (input.empty())
		return (-1);
	else if (!isOnlyNumeric(input))
		return (-2);
	try
	{
		index = std::stoi(input);
		index -= 1; //adjustment for a zero-based index
	}
	catch (const std::out_of_range&)
	{
		return (-2);
	}
	
	std::cout << "Index select is " << (index + 1) << std::endl;
	return (index);
}

static void selectContact(int count, Contact contact[])
{
	int index;

	while(true)
	{
		std::cout << "Select a contact by index (1 - " << std::min(count, 8) << "): ";
		index = getIndex();
		if (index == -1)
			return ;
		else if (index >= 0 && index < count && index < 8)
		{
			contact[index].displayContactDetails();
			return ;
		}
		else
			std::cout << "Invalid index. Please try again or press Enter to leave." << std::endl;
	}
}

void PhoneBook::searchContact()
{
	int index;

	if (this->count == 0)
	{
		std::cout << "Phonebook is empty. No contacts added yet." << std::endl;
		return ;
	}
	std::cout << TABLE << std::endl;
	for (index = 0; index < this->count && index < 8; index++)
	{
		this->contact[index].displayContact(index);
	}
	std::cout << std::endl;
	selectContact(this->count, this->contact);
}