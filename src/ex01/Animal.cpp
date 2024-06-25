/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/25 19:35:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("None")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &copyObj) : type(copyObj.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copyAssObj)
{
	if (this != &copyAssObj)
		this->type = copyAssObj.type;
	std::cout << "Animal assignment operator called" << std::endl;
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