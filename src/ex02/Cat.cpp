/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:55:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 17:39:47 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &copyObj) : AAnimal(copyObj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	if (this != &copyObj)
	{
		brain = new Brain();
		*this = copyObj;
	}
}

Cat &Cat::operator=(const Cat &copyAssObj)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copyAssObj)
	{
		AAnimal::operator=(copyAssObj);
		type = copyAssObj.type;
		*brain = *(copyAssObj.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete brain;
}
void Cat::makeSound() const
{
	std::cout << "Cat meows" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (brain);
}
