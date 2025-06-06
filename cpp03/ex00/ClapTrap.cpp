/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:22:14 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/06 11:31:05 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Parameterized constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		name = other.name;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		if (hitPoints == 0)
			std::cout << "ClapTrap " << name << " is dead! It has no hit points left." << std::endl;
		if (energyPoints == 0)
			std::cout << "ClapTrap " << name << " has no energy points left to attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead and cannot take more damage." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " is attacked and lost " << amount << " hit points" << std::endl;
	hitPoints -= amount;
	if (hitPoints <= 0)
		hitPoints = 0;
	attackDamage = amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
	{
		if (hitPoints == 0)
			std::cout << "ClapTrap " << name << " is dead and cannot be repaired." << std::endl;
		if (energyPoints == 0)
			std::cout << "ClapTrap " << name << " has no energy points left to repair." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " repairs itself, restoring " << amount << " hit points." << std::endl;
	hitPoints += amount;
	energyPoints--;
}