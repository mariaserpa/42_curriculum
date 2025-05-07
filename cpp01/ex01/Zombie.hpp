/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:23:44 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/07 12:19:04 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(); //constructor
		~Zombie(); //destructor

		void announce();
		void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
