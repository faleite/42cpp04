/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:44:56 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/28 16:05:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/**
 * 1. AMateria: Classe base abstrata que representa materiais mágicos.
 * 2. Ice: Derivada de AMateria, representa um material de gelo.
 * 3. Cure: Derivada de AMateria, representa um material de cura.
 * 4. IMateriaSource: Interface para a criação e armazenamento de matérias.
 * 5. MateriaSource: Implementação de IMateriaSource, que aprende e cria matérias.
 * 6. ICharacter: Interface para personagens que podem usar matérias.
 * 7. Character: Implementação de ICharacter, representando um personagem 
 * que pode equipar e usar matérias.
*/

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	
	bob->use(0, *me);
	bob->use(1, *me);
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
