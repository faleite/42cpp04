# C++
***(Modulo 04)***

## Index

01. **[Sub-typing polymorphism](#sub-typing-polymorphism)**
02. **[Abstract Classes](#abstract-classes)**
03. **[Interface](#interface)**
04. **[virtual functions](#virtual-functions)**
05. **[virtual destructor](#virtual-destructor)**
06. **[label virtual]()**

## Sub-typing polymorphism
**Definimos Polimorfismo** *como um princípio a partir do qual as classes derivadas de uma única classe base são capazes de invocar os métodos que, embora apresentem a mesma assinatura,comportam-se de maneira diferente para cada uma das classes derivadas. (A palavra significa ter muitas formas)*

**O Polimorfismo** *é um mecanismo por meio do qual selecionamos as funcionalidades utilizadas de forma dinâmica por um programa no decorrer de sua execução.*

*Com o Polimorfismo, os mesmos atributos e objetos podem ser utilizados em objetos distintos, porém, com implementações lógicas diferentes.*

-***Subtyping polymorphism***, também conhecido como **polimorfismo de subtipo** ou** polimorfismo de inclusão**, é um conceito da orientação a objetos onde um tipo derivado `(subtipo)` pode ser usado no lugar de um tipo base `(supertipo)`. Em outras palavras, um objeto de uma classe derivada pode ser tratado como se fosse um objeto da classe base. Isso permite que funções trabalhem com objetos de diferentes classes que compartilham a mesma interface ou superclasse.

**Destrutores Virtuais***: Sempre declare destrutores virtuais nas classes base para garantir que os destrutores das classes derivadas sejam chamados corretamente.*

***Exemplo:***
```cpp
#include <iostream>

// Classe base
class Animal {
public:
    // Construtor
    Animal() {
        std::cout << "Animal constructor called" << std::endl;
    }

    // Destrutor virtual
	/* O destrutor é virtual para garantir que o destrutor correto seja 
	chamado para objetos derivados. Ele também imprime uma mensagem 
	indicando que foi chamado.*/
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }

	// Função virtual pura (método abstrato)
	/* A classe Animal é uma classe base abstrata com um método virtual puro
	makeSound. Isso significa que Animal não pode ser instanciada diretamente.*/
    virtual void makeSound() const = 0;
};

// Classe derivada Dog
class Dog : public Animal {
public:
    // Construtor
    Dog() {
        std::cout << "Dog constructor called" << std::endl;
    }

    // Destrutor
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }

    // Sobrescrevendo o método makeSound
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

// Classe derivada Cat
class Cat : public Animal {
public:
    // Construtor
    Cat() {
        std::cout << "Cat constructor called" << std::endl;
    }

    // Destrutor
    ~Cat() {
        std::cout << "Cat destructor called" << std::endl;
    }

    // Sobrescrevendo o método makeSound
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Array de ponteiros para Animal
    Animal* animals[2];

    // Adicionando objetos Dog e Cat ao array
    animals[0] = new Dog();
    animals[1] = new Cat();

    // Loop através do array e chamando makeSound para cada animal
    for (int i = 0; i < 2; ++i) {
		/*Aqui, o polimorfismo entra em ação, pois a chamada para makeSound
		resolve para a versão apropriada do método (Dog ou Cat), dependendo 
		do tipo real do objeto.*/
        animals[i]->makeSound();
    }

    // Limpando a memória alocada dinamicamente
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    return 0;
}
```
[↑ Index ↑](#index)

## Abstract Classes
- Uma classe abstrata em C++ é uma classe que não pode ser instanciada diretamente. Ela serve como uma base para outras classes e pode conter métodos abstratos (métodos virtuais puros) que devem ser implementados pelas classes derivadas.
- Uma função virtual pura é aquela que deve ser substituída por qualquer classe derivada concreta. Isto é indicado na declaração com a ***sintaxe "=0"*** na declaração da função membro. É uma forma de forçar um contrato entre o designer da classe e os usuários dessa classe

***Exemplo:***
```cpp
#include <iostream>

// Classe abstrata Shape
class Shape {
public:
	/*Método Virtual Puro: virtual void draw() const = 0; faz de Shape uma classe
	abstrata. Esse método deve ser implementado pelas classes derivadas.*/
    virtual void draw() const = 0;

    // Método virtual comum com implementação padrão
	/*Tem uma implementação padrão, mas pode ser 
	sobrescrito pelas classes derivadas.*/
    virtual void move(int x, int y) {
        std::cout << "Moving shape to (" << x << ", " << y << ")" << std::endl;
    }

    // Destrutor virtual
    virtual ~Shape() {}
};

// Classe derivada Circle que herda de Shape
class Circle : public Shape {
public:
    // Implementação do método virtual puro draw
    void draw() const {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Classe derivada Square que herda de Shape
class Square : public Shape {
public:
    // Implementação do método virtual puro draw
    void draw() const {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle();
    shapes[1] = new Square();

    for (int i = 0; i < 2; ++i) {
        shapes[i]->draw();  // Polimorfismo em ação
        shapes[i]->move(10, 20);  // Chamando método da classe base
        delete shapes[i];  // Deletando objetos corretamente
    }

    return 0;
}
```
[↑ Index ↑](#index)

## Interface
- Uma interface é uma classe abstrata que só contém métodos virtuais puros. Em C++, não há uma palavra-chave específica para interfaces como em algumas outras linguagens (por exemplo, interface em Java), mas uma classe abstrata com todos os métodos virtuais puros funciona como uma interface.
- **Classes Abstratas**: Podem conter métodos virtuais puros e métodos com implementação padrão. Servem como base para outras classes.
- **Interfaces**: Em C++, são classes abstratas que só contêm métodos virtuais puros. Fornecem uma interface que as classes derivadas devem implementar.

***Exemplo:***
```cpp
#include <iostream>

// Interface Drawable
class Drawable {
public:
    // Métodos virtuais puros
    virtual void draw() const = 0;
    virtual void resize(int newSize) = 0;

    // Destrutor virtual puro
	/*O destrutor virtual puro deve ser definido fora da classe.*/
    virtual ~Drawable() = 0;
};

// Implementação do destrutor virtual puro fora da definição da classe
Drawable::~Drawable() {}

// Classe derivada Circle que implementa Drawable
class Circle : public Drawable {
public:
    void draw() const {
        std::cout << "Drawing a circle" << std::endl;
    }
    
    void resize(int newSize) {
        std::cout << "Resizing circle to " << newSize << std::endl;
    }
};

// Classe derivada Square que implementa Drawable
class Square : public Drawable {
public:
    void draw() const {
        std::cout << "Drawing a square" << std::endl;
    }
    
    void resize(int newSize) {
        std::cout << "Resizing square to " << newSize << std::endl;
    }
};

int main() {
    Drawable* drawables[2];
    drawables[0] = new Circle();
    drawables[1] = new Square();

    for (int i = 0; i < 2; ++i) {
        drawables[i]->draw();  // Polimorfismo em ação
        drawables[i]->resize(5);  // Chamando resize para cada objeto
        delete drawables[i];  // Deletando objetos corretamente
    }

    return 0;
}
```
[↑ Index ↑](#index)

## Virtual functions
- Quando uma função é declarada como virtual em uma classe base, ela pode ser substituída em qualquer classe derivada. A decisão de qual versão da função chamar é feita em tempo de execução com base no tipo do objeto, e não no tipo do ponteiro ou referência que aponta para o objeto.
-  Sempre que uma classe tem funções virtuais, seu destrutor também deve ser virtual para garantir a limpeza adequada de recursos.
- Funções virtuais puras (virtual void func() = 0;) podem ser usadas para declarar interfaces abstratas, forçando as classes derivadas a implementar essas funções.

***Exemplo:***
```cpp
#include <iostream>

// Classe base
class Animal {
public:
    // Função virtual
    virtual void makeSound() const {
        std::cout << "Animal makes a sound" << std::endl;
    }

    // Destrutor virtual
	/*Inclui um destrutor virtual para garantir que os destrutores das classes 
	derivadas sejam chamados corretamente quando um objeto é deletado através 
	de um ponteiro para a classe base*/
    virtual ~Animal() {}
};

// Classe derivada
class Dog : public Animal {
public:
    // Sobrescrita da função virtual
    void makeSound() const {
        std::cout << "Dog barks" << std::endl;
    }
};

// Classe derivada
class Cat : public Animal {
public:
    // Sobrescrita da função virtual
    void makeSound() const {
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Animal();
    Animal* animal2 = new Dog();
    Animal* animal3 = new Cat();

    animal1->makeSound(); // Chama Animal::makeSound()
    animal2->makeSound(); // Chama Dog::makeSound()
    animal3->makeSound(); // Chama Cat::makeSound()

    delete animal1;
    delete animal2;
    delete animal3;

    return 0;
}
```
[↑ Index ↑](#index)

## Virtual destructor
- Um destrutor virtual é uma característica importante em C++ quando se trabalha com herança. Ele garante que, ao deletar um objeto através de um ponteiro para a classe base, o destrutor da classe derivada seja chamado corretamente. Isso é essencial para evitar vazamentos de memória e garantir que todos os recursos sejam liberados corretamente.
- Quando alguém excluirá um objeto de classe derivada por meio de um ponteiro de classe base. Em particular, é aqui que você precisa tornar seu destruidor virtual:
  - se alguém derivar da sua classe,
  - e se alguém disser new Derived, onde Derived é derivado da sua classe,
  - e se alguém disser delete p, onde o tipo do objeto real é derivado, mas o tipo do ponteiro p é sua classe.

***Aqui está uma regra simplificada que geralmente protege você e geralmente não custa nada: torne seu destruidor virtual se sua classe tiver alguma função virtual.***

[↑ Index ↑](#index)

## Label virtual
- Quando uma função ou construtor é virtual na classe base em C++, é uma boa prática rotular explicitamente a mesma função ou construtor como virtual nas classes derivadas. Isso proporciona mais clareza e visibilidade ao código, indicando explicitamente que a função ou construtor está sendo sobrescrito nas classes derivadas para permitir o polimorfismo.
