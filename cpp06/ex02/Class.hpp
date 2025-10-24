/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:47:06 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/24 18:50:44 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

