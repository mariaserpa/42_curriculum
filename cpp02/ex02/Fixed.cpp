/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:53:19 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/04 16:38:26 by mrabelo-         ###   ########.fr       */
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

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->FixedPoint) / (1 << FractionalBits);
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &obj) const
{
	return this->FixedPoint > obj.FixedPoint;
}

bool Fixed::operator<(const Fixed &obj) const
{
	return this->FixedPoint < obj.FixedPoint;
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return this->FixedPoint >= obj.FixedPoint;
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return this->FixedPoint <= obj.FixedPoint;
}

bool Fixed::operator==(const Fixed &obj) const
{
	return this->FixedPoint == obj.FixedPoint;
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return this->FixedPoint != obj.FixedPoint;
}

//Floating-point arithmetic is natively supported by the CPU and 
//the C++ language, making it efficient and easy to use.
//The function is read-only and does not alter the state of the object.
Fixed Fixed::operator+(const Fixed &obj) const
{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed &Fixed::operator++() // Pre-increment
{
	this->FixedPoint += 1;
	return *this;
}

//The argument used just to differentiate it from pre-increment function
Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--() // Pre-decrement
{
	this->FixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

//The function cannot modify the Fixed objects passed to it.
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}
