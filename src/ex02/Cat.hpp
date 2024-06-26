/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:38:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/26 18:15:23 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

/**
 * Essas duas classes derivadas devem definir seu campo de tipo dependendo 
 * de seu nome. Então, o tipo do Dog será inicializado como "Dog", 
 * e o tipo do Cat será inicializado como "Cat".
 *
 * O tipo da classe Animal pode ser deixado em branco ou definido 
 * para o valor de sua escolha.
*/

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &copyObj);
		Cat &operator=(const Cat &copyAssObj);
		~Cat();
		
		void makeSound() const;
};

#endif // CAT_HPP