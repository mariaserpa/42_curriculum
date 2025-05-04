/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:48:07 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/04 12:18:49 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon; // Pointer because HumanB may not have a weapon

	public:
		HumanB(std::string name, Weapon *weapon = nullptr);
		~HumanB();
	
		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif