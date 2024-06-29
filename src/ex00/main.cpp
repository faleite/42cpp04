/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 18:46:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * Executar este código deve imprimir os sons específicos das classes Dog 
 * e Cat, não os do Animal.
*/
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	{
		std::cout << "\n/* Wrong Classes Tests 1 */\n" << std::endl;
		WrongCat c;
		WrongAnimal a(c);
		// retorna "WrongCat" porque o tipo foi copiado do objeto WrongCat.
		std::cout << a.getType() << " " << std::endl;
		// Como makeSound não é virtual em WrongAnimal, 
		// a função chamada é a versão de WrongAnimal.
		a.makeSound();
	}
	{	
		std::cout << "\n/* Wrong Classes Tests 2 */\n" << std::endl;
    	WrongCat c;
    	WrongAnimal* a = &c; // Usando um ponteiro
    	std::cout << a->getType() << " " << std::endl;
    	a->makeSound();
	}
	return 0;
}
