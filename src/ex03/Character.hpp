/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:25:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:16:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Amateria.hpp"

/** ???
 * Seu Character deve ter um construtor que tome seu nome como parâmetro. 
 * Qualquer cópia (usando construtor de cópia ou operador de 
 * atribuição de cópia) de um Personagem deve ser profunda
 */

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character();
		Character(const std::string &name);
		Character (const Character &copyObj);
		Character &operator=(const Character &copyAssin);
		~Character();

		// Pure virtual functions from ICharacter
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

# endif // CHARACTER_HPP