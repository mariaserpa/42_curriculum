/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:33:57 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/04 15:03:10 by mrabelo-         ###   ########.fr       */
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

		// Conversion Functions
		float toFloat(void) const;
		int toInt(void) const;

		// Other Member Functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
};

// The << operator is a non-member function because the left-hand operand of the operator is not an object of the class Fixed.
// Left Operand << Right Operand 
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif