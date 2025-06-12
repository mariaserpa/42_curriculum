/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:10:08 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/11 13:19:12 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testCorrectClass()
{
	std::cout << "\nTesting correct class hierarchy:" << std::endl;
	
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nAnimal type: " << animal->getType() << std::endl;
	animal->makeSound();

	std::cout << "\nDog type: " << dog->getType() << std::endl;
	dog->makeSound();

	std::cout << "\nCat type: " << cat->getType() << std::endl;
	cat->makeSound();
	
	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
}

void testWrongClass()
{
	std::cout << "\nTesting wrong class hierarchy:" << std::endl;
	const WrongAnimal* wAnimal = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();

	std::cout << "\nWrongAnimal type: " << wAnimal->getType() << std::endl;
	wAnimal->makeSound();

	std::cout << "\nWrongCat type: " << wCat->getType() << std::endl;
	wCat->makeSound();

	std::cout << std::endl;
	delete wAnimal;
	delete wCat;
}