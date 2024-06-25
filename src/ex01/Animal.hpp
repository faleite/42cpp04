/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/25 19:36:05 by faaraujo         ###   ########.fr       */
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

/* 
O DESTRUTOR VIRTUAL é virtual para garantir que o destrutor correto seja 
chamado para objetos derivados. Ele também imprime uma mensagem 
indicando que foi chamado.

Quando alguém excluirá um objeto de classe derivada por meio de um ponteiro 
de classe base. Em particular, é aqui que você precisa tornar seu destruidor 
virtual:
 - se alguém derivar da sua classe,
 - e se alguém disser new Derived, onde Derived é derivado da sua classe,
 - e se alguém disser delete p, onde o tipo do objeto real é derivado, 
mas o tipo do ponteiro p é sua classe.

Dica: torne seu destruidor virtual se sua classe tiver alguma função virtual.

Se você estiver apenas criando objetos diretamente e não manipulando objetos 
da classe derivada através de ponteiros ou referências da classe base, então 
não há necessidade de um destrutor virtual.
*/

/* METODO VIRTUAL
A razão para declarar um método como virtual em uma classe base é permitir 
o polimorfismo, o que significa que a chamada para o método será resolvida 
em tempo de execução (em vez de em tempo de compilação), permitindo que o 
método da classe derivada seja chamado mesmo quando o objeto é acessado 
através de um ponteiro ou referência para a classe base.

Se makeSound() não fosse declarado como virtual, a chamada 
myAnimal->makeSound() (do objeto Animal *myAnimal = new Dog();) 
sempre invocaria o método da classe base Animal, 
mesmo se myAnimal apontasse para um objeto Dog.
*/

/* `virtual void makeSound() const;`
const no final do metodo garante que o método não modifica o estado do objeto,
permitindo que eleseja chamado em objetos constantes.
*/

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copyObj);
		Animal &operator=(const Animal &copyAssObj);
		virtual ~Animal();
		
		const std::string& getType() const;
		virtual void makeSound() const;
};

#endif // ANIMAL_HPP