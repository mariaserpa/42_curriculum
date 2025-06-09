/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:21:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/06/06 21:29:16 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "Parameterized FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys()
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "FragTrap " << name << " is dead! It has no hit points left to high five." << std::endl;
}

