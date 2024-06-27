/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:29:04 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 22:35:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string type);
		Cure(const Cure &copyObj);
		Cure &operator=(const Cure &copyAssin);
		~Cure();
		
		// virtual member functions AMateria 
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif // CURE_HPP