/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:38:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 17:40:07 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copyObj) : Animal(copyObj)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	if (this != &copyObj)
	{
		brain = new Brain(); // Fix
		*this = copyObj;
	}
}

Dog &Dog::operator=(const Dog &copyAssObj)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copyAssObj) // Verifica auto-atribuição 
	{
		Animal::operator=(copyAssObj); // Chama o operador de atribuição da classe base
		type = copyAssObj.type; // Copia o membro `type` específico da classe `Dog`
		*brain = *(copyAssObj.brain); // FIX Cópia profunda
	}
	return (*this); // Retorna a referência ao objeto atual
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete brain;
}
void Dog::makeSound() const
{
	std::cout << "Dog barks" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (brain);
}
