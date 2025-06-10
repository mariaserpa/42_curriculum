/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:33:55 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/04 16:20:37 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : FixedPoint(integer << FractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPoint) : FixedPoint((roundf(floatingPoint * (1 << FractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
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

//By dividing the fixed-point integer by this scaling factor,
//the function reconstructs the original floating-point value that the fixed-point number represents.
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->FixedPoint) / (1 << FractionalBits);
}

//The right shift operator is used to divide the integer value by 2^n, 
//where n is the number of bits shifted. In this case, FractionalBits is 8, 
//so shifting right by 8 bits effectively divides the fixed-point value by 256.
//This operation extracts the integer part of the fixed-point number by discarding the fractional bits.
int Fixed::toInt(void) const
{
	return this->FixedPoint >> FractionalBits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // Check self-assignment
	{
		setRawBits(other.getRawBits());
	}
	return *this;
}

//Define how an fixed object should be represented when printed.
//The << operator is used for outputting objects to streams like std::cout
//The << operator provides a human-readable representation of the Fixed object when printed.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
