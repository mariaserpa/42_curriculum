/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:28:33 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/04 15:02:07 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	private:
	
		int FixedPoint;
		static const int FractionalBits = 8; //determines the precision of the fixed-point number
	
	public:
		
		// Constructors and Destructor
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();

		// Assignment Operator
		Fixed &operator=(const Fixed &other);

		// Other Member Functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
};

#endif