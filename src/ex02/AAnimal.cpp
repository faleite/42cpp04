/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 17:52:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("None")
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copyObj)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	if (this != &copyObj)
	{
		type = copyObj.type;
		*this = copyObj;
	}
}

AAnimal &AAnimal::operator=(const AAnimal &copyAssObj)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &copyAssObj)
		this->type = copyAssObj.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal made some sound" << std::endl;
}

const std::string &AAnimal::getType() const
{
	return (type);
}