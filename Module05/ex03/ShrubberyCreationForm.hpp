/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:34 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 13:22:17 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"
#include <fstream>


class AForm;
class Shrubbery : public AForm{

private:
	std::string target;
		
public:
	Shrubbery();
	Shrubbery(std::string _name);
	Shrubbery(const Shrubbery& other);
	virtual ~Shrubbery(void);

	std::string		getTarget(void) const;
	int				getCallIndex(void) const;

	Shrubbery		&operator=(const Shrubbery &other);
	
	bool			execute(Bureaucrat const & executor) const;
};

#endif