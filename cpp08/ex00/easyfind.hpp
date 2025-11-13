/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:06:27 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/13 16:02:18 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Element not found in container";
    }
};

//iterator is a general term for any type of iterator of the container T
//find is a STL algorithm that returns an iterator to the found element
template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}
