/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 15:54:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("None")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copyObj)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Animal &Animal::operator=(const Animal &copyAssObj)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copyAssObj)
		this->type = copyAssObj.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal made some sound" << std::endl;
}

const std::string &Animal::getType() const
{
	return (type);
}