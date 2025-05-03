/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:23:46 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/03 22:07:41 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N]; // Create an array of Zombies on the heap
	
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde); // Return the pointer to the array of Zombies
}