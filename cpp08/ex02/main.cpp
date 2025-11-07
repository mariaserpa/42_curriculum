/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:56:01 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/07 22:10:13 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Testing MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;  // Should print 17 because of LIFO behavior
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl; // Should print 1 because of LIFO behavior
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "MutantStack contents:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Test that we can create a std::stack from MutantStack
    std::stack<int> s(mstack);
	
    std::cout << "Created std::stack from MutantStack, size: " << s.size() << std::endl;
    
    std::cout << "\n=== Testing with std::list (for comparison) ===" << std::endl;
    
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << mlist.back() << std::endl;  // Should print top element 17
    
    mlist.pop_back();
    
    std::cout << mlist.size() << std::endl;  // Should print size of 1
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator it2 = mlist.begin();
    std::list<int>::iterator ite2 = mlist.end();
    
    ++it2;
    --it2;
    
    std::cout << "std::list contents:" << std::endl;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

	std::cout << "\n=== Testing MutantStack with string and reverse iterator ===" << std::endl;

	MutantStack<std::string> strStack;

	strStack.push("42!");
	strStack.push("Hello");
	strStack.push("World!");
	strStack.push("Hello");

	MutantStack<std::string>::reverse_iterator rit = strStack.rbegin();
	MutantStack<std::string>::reverse_iterator rite = strStack.rend();

	std::cout << "MutantStack (reverse) contents:" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

    return 0;
}