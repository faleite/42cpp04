# Notes

## Subject ex03

Interfaces não existem em C++98 (nem mesmo em C++20). No entanto, classes abstratas puras são comumente chamadas de interfaces. Portanto, neste último exercício, vamos tentar implementar interfaces para garantir que você tenha este módulo.

Complete a definição da seguinte classe **AMateria** e implemente as funções de membro necessárias.

```cpp
class AMateria
{
	protected:
	//	[...]
	public:
		AMateria(std::string const & type);
	//	[...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
```

Implemente as classes concretas de Materias **Ice** e **Cure**. Use seus nomes em letras minúsculas ("ice" para Ice, "cure" para Cure) para definir seus tipos. Claro, sua função membro clone() retornará uma nova instância do mesmo tipo (por exemplo, se você clonar uma Ice Materia,
você obterá uma nova Ice Materia).

A função membro use(ICharacter&) exibirá:

- Ice: "* dispara um raio de gelo em <nome> *"
- Cure: "* cura as feridas de <nome> *"

<nome> é o nome do Personagem passado como parâmetro. Não imprima os colchetes angulares (< e >).

***Ao atribuir uma Matéria a outra, copiar o tipo não faz sentido.***

Escreva a classe concreta **Character** que implementará a seguinte interface:

```cpp
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
```

O **Character** possui um inventário de 4 slots, o que significa 4 Materias no máximo. O inventário está vazio na construção. Eles equipam as Materias no primeiro slot vazio que encontram. Isso significa, nesta ordem: do slot 0 ao slot 3. Caso tentem adicionar uma Materia a um inventário cheio, ou usar/desequipar uma Materia inexistente, não faça nada (mas ainda assim, bugs são proibidos). A função membro unequip() NÃO deve excluir a Materia!

***Manipule as Materias que seu personagem deixou no chão como quiser. Salve os endereços antes de chamar unequip(), ou qualquer outra coisa, mas não se esqueça de que você tem que evitar vazamentos de memória.***

A função membro use(int, ICharacter&) terá que usar a Materia no slot[idx], e passar o parâmetro target para a função **AMateria**::use.

**O inventário do seu personagem será capaz de suportar qualquer tipo de AMateria.**

Seu **Character** deve ter um construtor que tome seu nome como parâmetro. Qualquer cópia (usando construtor de cópia ou operador de atribuição de cópia) de um Personagem deve ser **profunda**. Durante a cópia, as Materias de um Personagem devem ser excluídas antes que as novas sejam adicionadas ao seu inventário. Claro, as Materias devem ser excluídas quando um Personagem é destruído.

Escreva a classe concreta **MateriaSource** que implementará a seguinte interface:

```cpp
class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
```

- learnMateria(AMateria*)
Copia a Materia passada como parâmetro e armazena na memória para que possa ser clonada mais tarde. Assim como o Character, a **MateriaSource** pode conhecer no máximo 4 Materias. Elas não são necessariamente únicas.

- createMateria(std::string const &)
Retorna uma nova Materia. Esta última é uma cópia da Materia aprendida anteriormente pela **MateriaSource** cujo tipo é igual ao passado como parâmetro. Retorna 0 se o tipo for desconhecido.

Resumidamente, sua **MateriaSource** deve ser capaz de aprender "templates" de Materias para criá-las quando necessário. Então, você será capaz de gerar uma nova Materia usando apenas uma string que identifica seu tipo.
