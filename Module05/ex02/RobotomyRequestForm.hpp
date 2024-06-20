/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:21:03 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 13:22:14 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "AForm.hpp"

class AForm;
class Robotomy : public AForm{

private:
	std::string target;
	int			callIndex;
	bool		isRandomized;
		
public:
	Robotomy();
	Robotomy(std::string _name);
	Robotomy(const Robotomy& other);
	virtual ~Robotomy(void);

	std::string		getTarget(void) const;
	int				getCallIndex(void) const;

	Robotomy		&operator=(const Robotomy &other);
	
	bool			execute(Bureaucrat const & executor) const;
};

#endif