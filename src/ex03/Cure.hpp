/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:29:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/26 20:52:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string type);
		Cure(const Cure &copyObj);
		Cure &operator=(const Cure &copyAssin);
		~Cure();
		
		// virtual member functions AMateria 
		Cure* clone() const;
		void use(ICharacter& target);
};

Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(std::string type) : AMateria(type)
{
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &copyObj) : AMateria(copyObj)
{
	std::cout << "Cure Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Cure &Cure::operator=(const Cure &copyAssin)
{
	std::cout << "Cure Copy Assignment called" << std::endl;
	if (this != &copyAssin)
	{
		AMateria::operator=(copyAssin);
		type = copyAssin.type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure* Cure::clone() const
{
	Cure *newCure = new Cure("cure");
	return (newCure);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds";
	std::cout << " *" << std::endl;
}

#endif // CURE_HPP