/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:55:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 15:46:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copyObj) : WrongAnimal(copyObj)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

WrongCat &WrongCat::operator=(const WrongCat &copyAssObj)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &copyAssObj)
	{
		WrongAnimal::operator=(copyAssObj);
		type = copyAssObj.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat meows" << std::endl;
}
