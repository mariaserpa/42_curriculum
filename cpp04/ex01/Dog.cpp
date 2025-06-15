/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:08:22 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/15 19:55:01 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << getType() << " default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << getType() << " copy constructor called" << std::endl;
	brain = new Brain(*other.brain); //deep copy of the brain
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << getType() << " assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain; //free the existing brain
		brain = new Brain(*other.brain); //deep copy of the brain
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << getType() << " destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}

std::string Dog::getType() const
{
	return "Dog";
}