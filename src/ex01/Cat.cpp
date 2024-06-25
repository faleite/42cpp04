/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:55:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/25 20:40:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &copyObj) : Animal(copyObj)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copyAssObj)
{
	if (this != &copyAssObj) // Verifica auto-atribuição
	{
		Animal::operator=(copyAssObj);  // Chama o operador de atribuição da classe base
		type = copyAssObj.type; // Copia o membro `type` específico da classe `Dog`
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);  // Retorna a referência ao objeto atual
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "Cat meows" << std::endl;
}
