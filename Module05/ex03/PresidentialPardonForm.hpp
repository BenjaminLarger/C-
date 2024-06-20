/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:21:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 13:22:10 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef PRESIDENT_HPP
#define PRESIDENT_HPP

#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;
class President : public AForm{

private:
	std::string target;
	int			callIndex;
	bool		isRandomized;
		
public:
	President();
	President(std::string _name);
	President(const President& other);
	virtual ~President(void);

	std::string		getTarget(void) const;
	int				getCallIndex(void) const;

	President	&operator=(const President &other);
	
	bool		execute(Bureaucrat const & executor) const;
};

#endif