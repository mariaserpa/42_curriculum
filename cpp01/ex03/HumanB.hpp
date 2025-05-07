/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:48:07 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/07 12:23:11 by mrabelo-         ###   ########.fr       */
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
		HumanB(std::string name, Weapon *weapon = NULL);
		~HumanB();

		void attack(void);
		void setWeapon(Weapon &weapon);
};

#endif
