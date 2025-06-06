/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:47:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/06 21:18:52 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("ScavTrap 1");
	
	std::cout << "\n-----Testing-----" << std::endl;
	std::cout << "Hit Points of "<< scav.getName() << " is " << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points of "<< scav.getName() << " is " << scav.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of "<< scav.getName() << " is " << scav.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	scav.attack("target1");
	scav.takeDamage(30);
	scav.beRepaired(20);

	std::cout << "Hit Points of "<< scav.getName() << " is " << scav.getHitPoints() << std::endl;
	std::cout << "Energy Points of "<< scav.getName() << " is " << scav.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of "<< scav.getName() << " is " << scav.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	scav.guardGate();

	return 0;
}
