/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 16:03:20 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

static std::string		prompt_user(const char *prompt, const char *color)
{
	std::string 	user_input;

	std::cout << RESET << prompt << color;
	std::getline(std::cin, user_input);
	return (user_input);
}

int	main()
{
	std::string		user_prompt;
	Harl			harlObject;

	user_prompt = prompt_user(PROMPT, YELLOW);
	harlObject.complain(user_prompt);

	return (0);
}