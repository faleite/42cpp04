/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:38:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/25 21:59:13 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

/**
 * Essas duas classes derivadas devem definir seu campo de tipo dependendo 
 * de seu nome. Então, o tipo do Dog será inicializado como "Dog", 
 * e o tipo do Cat será inicializado como "Cat".
 *
 * O tipo da classe Animal pode ser deixado em branco ou definido 
 * para o valor de sua escolha.
*/

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &copyObj);
		Dog &operator=(const Dog &copyAssObj);
		~Dog();
		
		void makeSound() const;
};

#endif // DOG_HPP