/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/25 16:49:59 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

/**
 * Para cada exercício, você precisa fornecer os testes mais completos que puder.
 * Construtores e destrutores de cada classe devem exibir mensagens específicas. 
 * Não use a mesma mensagem para todas as classes.
 * 
 * Comece implementando uma classe base simples chamada Animal. 
 * Ela tem um atributo protegido:
 * 
 * std::string type;
 * 
 * Implemente uma classe Dog que herda de Animal.
 * Implemente uma classe Cat que herda de Animal.
 * 
 * Essas duas classes derivadas devem definir seu campo de tipo dependendo de 
 * seu nome. Então, o tipo do Dog será inicializado como "Dog" e o tipo do Cat 
 * será inicializado como "Cat". O tipo da classe Animal pode ser deixado 
 * em branco ou definido como o valor de sua escolha.
 * 
 * Todo animal deve ser capaz de usar a função membro:
 * makeSound()
 * 
 * Ele imprimirá um som apropriado (gatos não latem).
*/

/**
 * Para garantir que você entendeu como funciona, implemente uma classe 
 * WrongCat que herda de uma classe WrongAnimal. Se você substituir o 
 * Animal e o Cat pelos errados no código acima, o WrongCat 
 * deve emitir o som WrongAnimal.
 *
 * Implemente e entregue mais testes do que os fornecidos acima.
*/

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &copyObj);
		Animal &operator=(const Animal &copyAssObj);
		~Animal();
		
		void getType();
		void makeSound();
};

#endif // ANIMAL_HPP