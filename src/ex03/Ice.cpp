/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:54 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:24:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::Ice(std::string type) : AMateria(type)
{
	// std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice &copyObj) : AMateria(copyObj)
{
	// std::cout << "Ice Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Ice &Ice::operator=(const Ice &copyAssin)
{
	// std::cout << "Ice Copy Assignment called" << std::endl;
	if (this != &copyAssin)
	{
		AMateria::operator=(copyAssin);
		type = copyAssin.type;
	}
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice Destructor called" << std::endl;
}

Ice* Ice::clone() const
{
	Ice *newIce = new Ice("ice");
	return (newIce);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
}

