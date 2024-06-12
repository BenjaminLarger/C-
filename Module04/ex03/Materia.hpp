/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/12 20:56:05 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef MATERIAL_HPP
#define MATERIAL_HPP

// ----------INCLUDE
#include <iostream> 

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define DARK_RED "\033[2;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"
#define GREY "\033[1;30m"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class AMateria {

protected:
	std::string		type;
	
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria(void);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

class Ice : public AMateria {

private:

public:
	Ice();
	Ice(const Ice& other);
	Ice(std::string const & type);
	~Ice(void);

	virtual AMateria* clone() const;
};

class Cure : public AMateria {

private:
public:
	Cure();
	Cure(std::string const & _name);
	Cure(const Cure& other);
	~Cure(void);

	virtual AMateria* clone() const;
};


#endif