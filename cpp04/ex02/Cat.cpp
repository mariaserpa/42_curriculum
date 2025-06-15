/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:58:23 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/15 19:56:25 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << getType() << " default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << getType() << " copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << getType() << " assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << getType() << " destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}

std::string Cat::getType() const
{
	return "Cat";
}