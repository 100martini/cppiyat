#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\e[1;35mtests dial subject:\033[0m" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); 
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n\e[1;35mwrong_animal test:\033[0m" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); 
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n\e[1;35mADDITIONAL TESTS:\033[0m" << std::endl;
    std::cout << "\n\e[1;35mStack allocated objects:\033[0m" << std::endl;
    Animal animal;
    Dog dog;
    Cat cat;
    
    std::cout << "Animal type: " << animal.getType() << std::endl;
    std::cout << "Dog type: " << dog.getType() << std::endl;
    std::cout << "Cat type: " << cat.getType() << std::endl;
    
    std::cout << "Animal sound: ";
    animal.makeSound();
    std::cout << "Dog sound: ";
    dog.makeSound();
    std::cout << "Cat sound: ";
    cat.makeSound();
    
    std::cout << "\n\e[1;35mCopy constructor and assignment operator:\033[0m" << std::endl;
    Dog dog2 = dog;
    Cat cat2;
    cat2 = cat;
    
    std::cout << "Dog2 type: " << dog2.getType() << std::endl;
    std::cout << "Cat2 type: " << cat2.getType() << std::endl;
    
    std::cout << "Dog2 sound: ";
    dog2.makeSound();
    std::cout << "Cat2 sound: ";
    cat2.makeSound();
    
    return 0;
}