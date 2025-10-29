/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:54:01 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/28 11:06:23 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// Function templates allow you to write generic functions that work with different data types. 
// Instead of writing separate functions for each type, you write one template that can be instantiated for any type.
// Templates must be defined in header files because the compiler needs to see the template definition whenever it is used with a specific type.

// Basic function template syntax:
// template <typename T> or template <class T>
// typename keyword is a placeholder for a data type that will be specified when the function is called.


//reference to modify original variables
template <typename T>
void	swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
}

//reference to avoid copy unnecessary variables
template <typename T>
const	T& min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

//reference to avoid copy unnecessary variables
template <typename T>
const	T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}


