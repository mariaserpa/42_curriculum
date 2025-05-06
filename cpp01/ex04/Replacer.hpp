/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:42:21 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/04 23:30:56 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <fstream>

class Replacer
{
	private:
		std::string	filename;
		std::string	s1;
		std::string	s2;

	public:
		Replacer(const std::string &filename, const std::string &s1, const std::string &s2); //none of the arguments should be empty or should be changed
		~Replacer();
		
		void	replace();
};

#endif