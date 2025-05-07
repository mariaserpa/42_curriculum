/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:23:46 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/07 12:19:46 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie *horde = new Zombie[N]; // Create an array of Zombies on the heap

	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i + 1; // Convert the integer to a string
		horde[i].setName(name + "_" + ss.str());
	}
	return (horde); // Return the pointer to the array of Zombies
}

