/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:25:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/28 15:53:44 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("None")
{
	// std::cout << "Character Default constructor called" << std::endl;
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	// std::cout << "Character Default constructor called" << std::endl;
	this->_inventory[0] = NULL;
	this->_inventory[1] = NULL;
	this->_inventory[2] = NULL;
	this->_inventory[3] = NULL;
}

Character::Character(const Character &copyObj)
{
	// std::cout << "Character Copy Constructor called" << std::endl;
	if (this != &copyObj)
	{
		_inventory[0] = 0;
		_inventory[1] = 0;
		_inventory[2] = 0;
		_inventory[3] = 0;
		*this = copyObj;
	}
}

Character &Character::operator=(const Character &copyAssin)
{
	// std::cout << "Character Copy Assignment called" << std::endl;
	if (this != &copyAssin)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = 0;
			}
			if (copyAssin._inventory[i])
				_inventory[i] = copyAssin._inventory[i]->clone();
		}
		_name = copyAssin._name;
	}
	return (*this);
}

Character::~Character()
{
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

// Pure virtual functions from ICharacter
std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		// std::cout << "Materia passed is NULL, failed to equip" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			// std::cout << "Materia " << _name << " added on slot: ";
			// std::cout << i << std::endl;
			return ;
		}
	}
	// std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
	{
		std::cout << "Materia " << _name << " failed to unequip" << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !_inventory[idx])
	{
		std::cout << "Materia " << _name << " failed to use" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
