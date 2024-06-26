/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/26 18:14:30 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
Uma cópia de um Cachorro ou Gato não deve ser superficial. 
Portanto, você tem que testar se suas cópias são cópias profundas!.
*/
int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;
	
	size_t numAnimals(6);
	AAnimal *animals[numAnimals];
	
	std::cout << "\n/* MORE TESTS */\n" << std::endl;
	
	for (size_t numObjs = 0; numObjs < numAnimals; numObjs++)
	{
		if (numObjs < numAnimals / 2)
			animals[numObjs] = new Dog();
		else
			animals[numObjs] = new Cat();
	}
	
	for (size_t numObjs = 0; numObjs < numAnimals; numObjs++)
	{
		std::cout << animals[numObjs]->getType() << " " << (numObjs + 1);
		std::cout << std::endl;
		animals[numObjs]->makeSound();
		std::cout << std::endl;
	}

	for (size_t numObjs = 0; numObjs < numAnimals; numObjs++)
	{
		delete animals[numObjs];
	}
	
	return 0;
}
