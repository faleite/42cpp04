/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:22:56 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/26 20:29:23 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter; //

class AMateria
{
	protected:
		std::string type; //
	public:
		AMateria(); //
		AMateria(std::string const & type); //
		AMateria(const AMateria &copyObj); //
		AMateria &operator=(const AMateria &copyAssin); //
		virtual ~AMateria(); //

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copyObj)
{
	std::cout << "AMateria Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

AMateria &AMateria::operator=(const AMateria &copyAssin)
{
	std::cout << "AMateria Copy Assignment called" << std::endl;
	if (this != &copyAssin)
		this->type = copyAssin.type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMteria Default " << target.getName() << " *" << std::endl;
}

#endif // AMATERIA_HPP
