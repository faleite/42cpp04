/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:29:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 22:48:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(std::string type) : AMateria(type)
{
	// std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &copyObj) : AMateria(copyObj)
{
	// std::cout << "Cure Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Cure &Cure::operator=(const Cure &copyAssin)
{
	// std::cout << "Cure Copy Assignment called" << std::endl;
	if (this != &copyAssin)
	{
		AMateria::operator=(copyAssin);
		type = copyAssin.type;
	}
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure Destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	Cure *newCure = new Cure("cure");
	return (newCure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds";
	std::cout << " *" << std::endl;
}
