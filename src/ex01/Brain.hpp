/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:22:13 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/28 17:24:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

/*
Implemente uma classe Brain. Ela contém um array de 100 std::string chamado ideas.
Dessa forma, Dog e Cat terão um atributo Brain* privado.
Após a construção, Dog e Cat criarão seu Brain usando new Brain();
Após a destruição, Dog e Cat excluirão seu Brain.

Na sua função principal, crie e preencha um array de objetos Animal. 
Metade dele serão objetos Dog e a outra metade serão objetos Cat. 
No final da execução do seu programa, faça um loop sobre esse array 
e exclua todos os Animal. Você deve excluir diretamente dogs e cats como Animals. 
Os destrutores apropriados devem ser chamados na ordem esperada.

Não se esqueça de verificar se há vazamentos de memória.

Uma cópia de um Dog ou Cat não deve ser superficial. Portanto, 
você precisa testar se suas cópias são cópias profundas!
*/

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