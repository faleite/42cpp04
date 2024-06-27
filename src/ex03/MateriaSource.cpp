/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:41:30 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 22:42:29 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource Default constructor called" << std::endl;
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
}

MateriaSource::MateriaSource (const MateriaSource &copyObj)
{
	// std::cout << "MateriaSource Copy Constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copyAssin)
{
	// std::cout << "MateriaSource Copy Assignment called" << std::endl;
	if (this != &copyAssin)
	{
		for (int i = 0; i < 4; i++)
            delete _inventory[i];
		for (int i = 0; i < 4; i++)
			_inventory[i] = copyAssin._inventory[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
        if (_inventory[i])
			delete _inventory[i];
	}
}

// Pure virtual functions from IMateriaSource
void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		// std::cout << "MateriaSource failed to learn" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			// std::cout << "MateriaSource learned, saved on slot: ";
			// std::cout << i << std::endl;
			return ;
		}
	}
	// std::cout << "MateriaSource failed to learn" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			if (_inventory[i]->getType() == type)
			{
				// std::cout << "MateriaSource created: " << type << std::endl;
				return (_inventory[i]->clone());
			}
		}
	}
	// std::cout << "MateriaSource failed to create: " << type << std::endl;
	return (0);
}
