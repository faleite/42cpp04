/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:22:13 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:22:28 by faaraujo         ###   ########.fr       */
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