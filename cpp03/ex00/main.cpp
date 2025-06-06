/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:21:40 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/06 21:37:30 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap claptrap1("Clappy 1");
	std::cout << "\n-----Testing Hit Points and Energy Points-----" << std::endl;
	std::cout << "Hit Points of "<< claptrap1.getName() << " is " << claptrap1.getHitPoints() << std::endl;
	std::cout << "Energy Points of "<< claptrap1.getName() << " is " << claptrap1.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of "<< claptrap1.getName() << " is " << claptrap1.getAttackDamage() << std::endl;
	std::cout << std::endl;

	claptrap1.attack("target1");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);

	std::cout << std::endl;
	std::cout << "Hit Points of "<< claptrap1.getName() << " is " << claptrap1.getHitPoints() << std::endl;
	std::cout << "Energy Points of "<< claptrap1.getName() << " is " << claptrap1.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of "<< claptrap1.getName() << " is " << claptrap1.getAttackDamage() << std::endl;

	std::cout << "\n-----Testing Attack Points-----" << std::endl;
	for (int i = 0; i < 10; i++) {
        claptrap1.attack("target1");
    }
    claptrap1.attack("target1");

	std::cout << "\n-----Testing Exceding Energy Points-----" << std::endl;
	std::cout << "Hit Points of "<< claptrap1.getName() << " is " << claptrap1.getHitPoints() << std::endl;
	std::cout << "Energy Points of "<< claptrap1.getName() << " is " << claptrap1.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of "<< claptrap1.getName() << " is " << claptrap1.getAttackDamage() << std::endl;

	claptrap1.takeDamage(3);
	claptrap1.attack("target1");
	claptrap1.beRepaired(5);

	ClapTrap claptrap2("Clappy 2");
	std::cout << "\n-----Testing Exceding Damage of Hit Points-----" << std::endl;
	std::cout << "Hit Points of "<< claptrap2.getName() << " is " << claptrap2.getHitPoints() << std::endl;
	std::cout << "Energy Points of "<< claptrap2.getName() << " is " << claptrap2.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage of "<< claptrap2.getName() << " is " << claptrap2.getAttackDamage() << std::endl;

	claptrap2.takeDamage(12);
	claptrap2.attack("target2");
	claptrap2.beRepaired(5);

	return 0;
}
