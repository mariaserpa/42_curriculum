/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:53:56 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/04 23:27:44 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(const std::string &filename, const std::string &s1, const std::string &s2)
	: filename(filename), s1(s1), s2(s2)
{
	if (this->filename.empty() || s1.empty())
		throw std::invalid_argument("Filename or the replace string (s1) cannot be empty");
}

Replacer::~Replacer() {}

void Replacer::replace()
{
	std::ifstream input(this->filename.c_str());
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file " << this->filename << std::endl;
		return ;
	}
	std::ofstream output((this->filename + ".replace").c_str());
	if (!output)
	{
		std::cerr << "Error: " << (this->filename + ".replace") << " could not be created." << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(input, line))
	{
		size_t pos = 0;
		while ((pos = line.find(this->s1, pos)) != std::string::npos)
		{
			line.erase(pos, this->s1.length());
			line.insert(pos, this->s2);
			pos += this->s2.length();
		}
		output << line << std::endl;
	}
}