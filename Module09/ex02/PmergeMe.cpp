/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:29:16 by blarger           #+#    #+#             */
/*   Updated: 2024/06/30 14:33:09 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "PmergeMe.hpp"

//https://github.com/nerraou/Ford-Johnson-algorithm/tree/master?tab=readme-ov-file

void	displayTimeToProcess(std::clock_t start, std::clock_t end, std::string containerUsed)
{
	double duration = (end - start) * (1000000 / CLOCKS_PER_SEC);

	std::cout << "Time to process a range of 3000 elements with std::" << containerUsed << " : " << duration << " us" << std::endl;
}

void	displayNbBeforeOrdering(char **argv)
{
	int	i = 1;

	std::cout << "Before:	";
	while (argv[i])
	{
		std::cout << argv[i];
		i++;
		if (argv[i])
			std::cout << " ";	
	}
	std::cout << std::endl;
	if (i == 2)
	{
		std::cout << "After:	" << argv[1] << std::endl;
	}
}