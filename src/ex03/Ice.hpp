/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:27:54 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:16:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string type);
		Ice(const Ice &copyObj);
		Ice &operator=(const Ice &copyAssin);
		~Ice();
		
		// virtual member functions AMateria 
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif // ICE_HPP
