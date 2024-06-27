/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:22:56 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:23:26 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	// std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copyObj)
{
	// std::cout << "AMateria Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

AMateria &AMateria::operator=(const AMateria &copyAssin)
{
	// std::cout << "AMateria Copy Assignment called" << std::endl;
	if (this != &copyAssin)
		this->type = copyAssin.type;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMteria Default " << target.getName() << " *" << std::endl;
}
