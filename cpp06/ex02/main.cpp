/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:01:32 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/24 14:31:09 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // for std::rand
#include <iostream>

// dynamic_cast: used for safe downcasting in an inheritance hierarchy.
// It ensures that the cast is valid at runtime, returning nullptr for pointers
// that are not of the target type.

Base* generate()
{
	std::srand(static_cast<unsigned int>(std::time(0))); // seed the random number generator
	switch(std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

// prints the type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p)
{
	if (!p)
	{
		std::cout << "Null pointer provided." << std::endl;
		return;
	}
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type." << std::endl;
}

// prints the type of the object referenced by p: "A", "B", or "C".
void identify(Base& p)
{
	try
	{
		void(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
		return;
	} catch (...) {} // Ignore exception and try next
	try
	{
		void(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
		return;
	} catch (...) {} // Ignore exception and try next
	try
	{
		void(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
		return;
	} catch (...) {} // Ignore exception and try next
	std::cout << "Unknown type." << std::endl;
}

int main()
{
	Base* basePtr = generate();
	
	std::cout << "Identifying via pointer: " << std::endl;
	identify(basePtr);
	
	std::cout << "Identifying via reference: " << std::endl;
	identify(*basePtr);

	delete basePtr;
	return 0;
}