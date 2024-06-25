/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:50 by blarger           #+#    #+#             */
/*   Updated: 2024/06/25 17:22:39 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"

int main()
{
	std::cout << YELLOW << "TEST 1---------------------------------" << RESET << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top : " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int, std::deque<int> >::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << "element : " <<  *it << std::endl;
		++it;
	}
	std::cout << YELLOW << "TEST 2---------------------------------" << RESET << std::endl;
	
	MutantStack<int, std::vector<int> > vectorStack;
	
	vectorStack.push(1);
	vectorStack.push(2);
	vectorStack.push(3);

	std::cout << "top : " << vectorStack.top() << std::endl;

	vectorStack.pop();
	std::cout << "size : " << vectorStack.size() << std::endl;

	MutantStack<int, std::vector<int> >::iterator _it = vectorStack.begin();
	MutantStack<int, std::vector<int> >::iterator ite_ = vectorStack.end();

	++_it;
	--_it;
	while (_it != ite_)
	{
		std::cout << "element : " <<  *_it << std::endl;
		++_it;
	}

	return 0;
}
