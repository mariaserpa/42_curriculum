/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:23:46 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/03 22:20:06 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (nullptr);
		
	Zombie *horde = new Zombie[N]; // Create an array of Zombies on the heap
	
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name + "_" + std::to_string(i + 1));
	}
	return (horde); // Return the pointer to the array of Zombies
}