/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:35:24 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/10/29 10:58:08 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>  // for std::size_t
# include <exception> // for std::exception

template <typename T>
class Array
{
	public:
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Array index out of range";
				}
		};
	private:
		T*	array;
		unsigned int	n;
	public:
		Array() : array(NULL), n(0) {}
		// explicit to avoid implicit conversions
		explicit Array(unsigned int s) : array(new T[s]()), n(s) {}
		Array(const Array& other) : array(NULL), n(other.n)
		{
			if (n > 0)
			{
				array = new T[n];
				for (unsigned int i = 0; i < n; i++)
				{
					array[i] = other.array[i];
				}
			}
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] array;
				array = NULL;
				n = other.n;
				if (n > 0)
				{
					array = new T[n];
					for (unsigned int i = 0; i < n; i++)
					{
						array[i] = other.array[i];
					}
				}
				else
					array = NULL;
			}
			return *this;
		}
		~Array() { delete[] array; }

		T& operator[](unsigned int index)
		{
			if (index >= n)
				throw OutOfRangeException();
			return array[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= n)
				throw OutOfRangeException();
			return array[index];
		}

		unsigned int size() const { return n; }
};

