/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 18:55:13 by faaraujo         ###   ########.fr       */
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
	// AAnimal a; // Not work, this a abstract function
	// a.makeSound();
	
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
	
	Dog *dog1 = new Dog();
	Dog cat;
	
	dog1->getBrain()->setIdea(0, "Is that a bone?");
	Dog dog2 (*dog1);
	cat.getBrain()->setIdea(0, "Hey Dogs, have you had your morning bath yet?");
	dog2.getBrain()->setIdea(1, "I did my poop, now I'm going after the bone");
	cat.getBrain()->setIdea(1, "Oh no dog, hide your poop");

	std::cout << "\n** Show Ideas (deep copy tests) **\n";
	std::cout << "Dog1's idea: " << dog1->getBrain()->getIdea(0) << std::endl;
	delete dog1;
    std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat's idea: " << cat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat's idea: " << cat.getBrain()->getIdea(1) << std::endl;
	std::cout << "** End of Ideas **\n" << std::endl;
	
	return 0;
}
