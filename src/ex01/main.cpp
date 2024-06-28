/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/28 18:32:41 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

/**
Uma cópia de um Cachorro ou Gato não deve ser superficial. 
Portanto, você tem que testar se suas cópias são cópias profundas!.
*/
int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j;//should not create a leak
	// delete i;
		
	// size_t numAnimals(6);
	// Animal *animals[numAnimals];
	
	// std::cout << "\n/* MORE TESTS */\n" << std::endl;
	
	// for (size_t numObjs = 0; numObjs < numAnimals; numObjs++)
	// {
	// 	if (numObjs < numAnimals / 2)
	// 		animals[numObjs] = new Dog();
	// 	else
	// 		animals[numObjs] = new Cat();
	// }
	
	// for (size_t numObjs = 0; numObjs < numAnimals; numObjs++)
	// {
	// 	std::cout << animals[numObjs]->getType() << " " << (numObjs + 1);
	// 	std::cout << std::endl;
	// 	animals[numObjs]->makeSound();
	// 	std::cout << std::endl;
	// }

	// for (size_t numObjs = 0; numObjs < numAnimals; numObjs++)
	// {
	// 	delete animals[numObjs];
	// }
	
	Dog dog1;
	dog1.makeSound();
	
	dog1.getBrain()->setIdea(0, "Idea from dog1");
	Dog dog2(dog1);

	std::cout << "Dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	
	return 0;
}
