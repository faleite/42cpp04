/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:41:30 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 21:16:54 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_inventory[4];
	public:
		MateriaSource();
		MateriaSource (const MateriaSource &copyObj);
		MateriaSource &operator=(const MateriaSource &copyAssin);
		~MateriaSource();

		// Pure virtual functions from IMateriaSource
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP