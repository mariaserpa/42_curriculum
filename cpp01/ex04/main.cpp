/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:14:10 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/05/04 23:27:20 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ex04 <int1> <int2> <int3>" << std::endl;
		return (1);
	}
	try
	{
		Replacer replacer(argv[1], argv[2], argv[3]);
		replacer.replace();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}