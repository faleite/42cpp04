/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:22:56 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:15:58 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter; //

class AMateria
{
	protected:
		std::string type; //
	public:
		AMateria(); //
		AMateria(std::string const & type); //
		AMateria(const AMateria &copyObj); //
		AMateria &operator=(const AMateria &copyAssin); //
		virtual ~AMateria(); //

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP
