/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:18:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 18:04:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

/**
 * Criar objetos Animal não faz sentido, afinal. É verdade, eles não fazem som!
 *
 * Para evitar possíveis erros, a classe Animal padrão não deve ser instanciável. 
 * Corrija a classe Animal para que ninguém possa instanciá-la. 
 * Tudo deve funcionar como antes.
 *
 * Se quiser, você pode atualizar o nome da classe adicionando um prefixo 
 * A a Animal
 */

/** Classe Abstrata
 * Uma classe abstrata em C++ é uma classe que não pode ser instanciada 
 * diretamente. Ela serve como uma base para outras classes e pode conter 
 * métodos abstratos (métodos virtuais puros) que devem ser implementados 
 * pelas classes derivadas.
*/
class AAnimal
{
	protected:
		std::string type;
		AAnimal(const std::string& type);
	public:
		AAnimal();
		AAnimal(const AAnimal &copyObj);
		AAnimal &operator=(const AAnimal &copyAssObj);
		virtual ~AAnimal();
		
		const std::string& getType() const;
		/*Método Virtual Puro: faz desta classe uma classe abstrata.
		Esse método deve ser implementado pelas classes derivadas.*/
		virtual void makeSound() const = 0;
};

#endif // AANIMAL_HPP