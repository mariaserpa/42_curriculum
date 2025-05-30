/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:59 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/03 21:19:26 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor doesn't need a return type
Zombie::Zombie(std::string name)
{
	this->name = name;
}

// Destructor doesn't need a return type
Zombie::~Zombie()
{
	std::cout << this->name << " was destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}