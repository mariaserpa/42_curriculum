/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:53:22 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/04 15:07:48 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	private:
	
		int FixedPoint;
		static const int FractionalBits = 8;
	
	public:
	
		// Constructors and Destructor
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		Fixed(const Fixed &other);
		~Fixed();

		// Assignment Operator
		Fixed &operator=(const Fixed &other);

		// Comparison Operators
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
		
		// Arithmetic Operators
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		// Increment and Decrement Operators
		Fixed &operator++(); // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed &operator--(); // Pre-decrement
		Fixed operator--(int); // Post-decrement
		
		// Min and Max Functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
		// Conversion Functions
		float toFloat(void) const;
		int toInt(void) const;

		// Other Member Functions
		int getRawBits(void) const;
		void setRawBits(int const raw);

};


std::ostream &operator<<(std::ostream &out, const Fixed &fixed);




#endif