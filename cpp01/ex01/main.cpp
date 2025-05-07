/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:23:38 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/07 12:22:07 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 4;
	Zombie *horde = zombieHorde(N, "Zombie_Horde");

	for (int i = 0; i < N; ++i)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
