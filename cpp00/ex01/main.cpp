/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:42:29 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/04 17:37:45 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	PhoneBook phonebook; //instance of PhoneBook

	std::string input;
	bool running = true;

	while(running)
	{
		std::cout << "Please enter a command (Options: ADD, SEARCH, EXIT): " << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nExiting due to EOF." << std::endl;
			exit(0);
		}
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
		{
			running = false;
			std::cout << "Exiting the program." << std::endl;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
}
