/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:40:50 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/03 22:46:06 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain; // Pointer to string variable
	std::string &brainRef = brain; // Reference to string variable

	std::cout << "The memory address of the string variable: " << &brain << std::endl;
	std::cout << "The memory address held by brainPtr: " << brainPtr << std::endl;
	std::cout << "The memory address held by brainRef: " << &brainRef << std::endl;

	std::cout << "The value of the string variable: " << brain << std::endl;
	std::cout << "The value pointed to by brainPtr: " << *brainPtr << std::endl;
	std::cout << "The value pointed to by brainRef: " << brainRef << std::endl;
	
}
