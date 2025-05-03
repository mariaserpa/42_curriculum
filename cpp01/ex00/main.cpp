/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:55 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/03 21:17:24 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	// Heap allocation
	Zombie *zombie = newZombie("Zombie1");
	zombie->announce();
	delete zombie; // need to delete the zombie to free the memory

	// Stack allocation
	randomChump("Zombie2");

	return (0);
}