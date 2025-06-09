/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:33:46 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/06 21:38:29 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap frag("FragTrap 1");

	std::cout << "\n-----Testing-----" << std::endl;
	std::cout << "Hit Points of " << frag.getName() << " is " << frag.getHitPoints() << std::endl;
	std::cout << "Energy Points of " << frag.getName() << " is " << frag.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of " << frag.getName() << " is " << frag.getAttackDamage() << std::endl;
	std::cout << std::endl;

	frag.attack("target1");
	frag.takeDamage(20);
	frag.beRepaired(10);

	std::cout << "Hit Points of " << frag.getName() << " is " << frag.getHitPoints() << std::endl;
	std::cout << "Energy Points of " << frag.getName() << " is " << frag.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of " << frag.getName() << " is " << frag.getAttackDamage() << std::endl;
	std::cout << std::endl;

	frag.highFivesGuys();

	return 0;
}