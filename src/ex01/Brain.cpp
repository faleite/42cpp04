/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:22:13 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 17:25:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &copyObj)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	
	if (this != &copyObj)
		*this = copyObj;
}

Brain &Brain::operator=(const Brain &copyAssObj)
{
	std::cout << "Brain assignment operator called" << std::endl;
	
	if (this != &copyAssObj)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = copyAssObj.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		throw std::out_of_range("Index out of bounds");
	return (ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		throw std::out_of_range("Index out of bounds");
	ideas[index] = idea;
}
