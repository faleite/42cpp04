/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:38:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 17:39:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copyObj) : AAnimal(copyObj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	if (this != &copyObj)
	if (this != &copyObj)
	{
		brain = new Brain();
		*this = copyObj;
	}
}

Dog &Dog::operator=(const Dog &copyAssObj)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copyAssObj)
	{
		AAnimal::operator=(copyAssObj);
		type = copyAssObj.type;
		*brain = *(copyAssObj.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "Dog barks" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (brain);
}
