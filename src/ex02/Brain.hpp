/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:22:13 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/29 17:07:04 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copyObj);
		Brain &operator=(const Brain &copyAssObj);
		virtual ~Brain();

		const std::string &getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif // BRAIN_HPP