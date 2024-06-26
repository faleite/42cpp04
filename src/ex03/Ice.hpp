/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:54 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/26 20:48:21 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string type);
		Ice(const Ice &copyObj);
		Ice &operator=(const Ice &copyAssin);
		~Ice();
		
		// virtual member functions AMateria 
		Ice* clone() const;
		void use(ICharacter& target);
};

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::Ice(std::string type) : AMateria(type)
{
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice &copyObj) : AMateria(copyObj)
{
	std::cout << "Ice Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Ice &Ice::operator=(const Ice &copyAssin)
{
	std::cout << "Ice Copy Assignment called" << std::endl;
	if (this != &copyAssin)
	{
		AMateria::operator=(copyAssin);
		type = copyAssin.type;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
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

#endif // ICE_HPP
