/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:10:57 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/15 20:51:40 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class RPN
{
	private: //since we just need the return of the calculation, there is no need for instantiation
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
	public:
		static double executeCalc(const std::string &string);
};