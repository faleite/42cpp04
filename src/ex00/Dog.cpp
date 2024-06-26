/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:38:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/26 16:39:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &copyObj) : Animal(copyObj)
{
	if (this != &copyObj)
		*this = copyObj;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copyAssObj)
{
	if (this != &copyAssObj) // Verifica auto-atribuição 
	{
		Animal::operator=(copyAssObj); // Chama o operador de atribuição da classe base
		type = copyAssObj.type; // Copia o membro `type` específico da classe `Dog`
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this); // Retorna a referência ao objeto atual
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}
void Dog::makeSound() const
{
	std::cout << "Dog barks" << std::endl;
}
