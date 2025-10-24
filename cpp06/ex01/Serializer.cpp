/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:02:53 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/24 14:24:26 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//reinterpret_cast it is used to convert a pointer of some data type 
//into a pointer of another data type, even if the data types before 
//and after conversion are different.

//convert Data* to uintptr_t (unsigned integer type capable of holding a pointer)
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

//convert uintptr_t back to Data*
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}