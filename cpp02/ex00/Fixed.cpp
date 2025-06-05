/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:36 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/04 16:18:02 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Although the member variable is not const or reference type,
//I initialized it with an initializer list because it is a good practice
Fixed::Fixed() : FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : FixedPoint(other.FixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->FixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->FixedPoint = raw;
}

//Returning a reference avoids creating a copy of the object, 
//so it ensures that the returned object is the same as the one being assigned to (a = b modifies a directly)
//passing the parameter by reference avoids unnecessary copying of the object by referring to the original object
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // Check self-assignment
	{
		setRawBits(other.getRawBits());
	}
	return *this;
}
