/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:16:31 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/12 17:03:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testDog()
{
	std::cout << "\n=== Dog Tests ===\n" << std::endl;

	Dog dog1;
	dog1.makeSound();
	dog1.getBrain()->setIdea(0, "I'm hungry");
	std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Copy constructor test
	Dog dog2(dog1);
	dog2.makeSound();
	std::cout << "Dog2 idea 0 before change: " << dog2.getBrain()->getIdea(0) << std::endl;
	dog2.getBrain()->setIdea(0, "I want to play");
	std::cout << "Dog2 idea 0 after change: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1 idea 0 (original idea): " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Assignment operator test
	Dog dog3;
	dog3.makeSound();
	dog3.getBrain()->setIdea(0, "I want to sleep");
	std::cout << "Dog3 idea 0: " << dog3.getBrain()->getIdea(0) << std::endl;
    dog3 = dog1;
	std::cout << "Dog3 idea 0 after assignment: " << dog3.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
}

void testCat()
{
	std::cout << "\n=== Cat Tests ===\n" << std::endl;

	Cat cat1;
	cat1.makeSound();
	cat1.getBrain()->setIdea(0, "I want to sleep");
	std::cout << "Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Copy constructor test
	Cat cat2(cat1);
	cat2.makeSound();
	std::cout << "Cat2 idea 0 before change: " << cat2.getBrain()->getIdea(0) << std::endl;
	cat2.getBrain()->setIdea(0, "I want to destroy the sofa");
	std::cout << "Cat2 idea 0 after change: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	// Assignment operator test
	Cat cat3;
	cat3.makeSound();
	cat3.getBrain()->setIdea(0, "I demand food");
	std::cout << "Cat3 idea 0: " << cat3.getBrain()->getIdea(0) << std::endl;
	cat1 = cat2;
	std::cout << "Cat3 idea 0 after assignment: " << cat3.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
}

void testAnimal()
{
	std::cout << "\n=== Animal Array Test ===\n" << std::endl;

	int n = 5;
	const Animal *animals[n];

	for (int i = 0; i < n; i++)
	{
		if (i < n / 2 )
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete animals[i];
		animals[i] = NULL;
		std::cout << std::endl;
	}
}
