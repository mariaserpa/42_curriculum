/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:41:07 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/28 11:19:14 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef> // for std::size_t

// when using typename F, the func parameter can accept any callable type, and support both const and non-const references
template <typename T, typename F>
void iter(T* array, std::size_t length, F func)
{
	if (!array || !length)
		return;
	std::size_t i = 0;
	while (i < length)
	{
		func(array[i]);
		i++;
	}
}
