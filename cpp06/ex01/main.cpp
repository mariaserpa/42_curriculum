/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:29:03 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/23 22:17:50 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data = {42, "Hello, 42!"};
	std::cout << "Original object address: " << &data << ", object id: " << data.a << ", object name: " << data.b << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data* new_data = Serializer::deserialize(raw);

	std::cout << "Deserialized object address: " << &new_data << ", object id: " << new_data->a << ", object name: " << new_data->b << std::endl;
	return 0;
}