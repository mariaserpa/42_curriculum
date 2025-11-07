/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:56:08 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/07 21:51:54 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

//std::stack is actually a container adaptor and it doesn't have initially methods like begin() and end()
//std::stack should initally only allow access to the top element (LIFO access - "Last In, First Out")
//std::stack internally uses a container (usually std::deque)
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack() {}
		
		// Creating type aliases (typedef) for iterator types
		typedef typename std::stack<T>::container_type::iterator	iterator; //can modify elements
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator; //read-only access
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator; //iterate backwards
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator; //read-only backwards

		//functions of each iterator type
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};