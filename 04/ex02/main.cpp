#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound();
    j->makeSound();
    
    delete j;
    delete i;
    
    std::cout << "\n\e[1;35marrays:\033[0m" << std::endl;
    const int numAnimals = 4;
    AAnimal* animals[numAnimals];
    
    for (int k = 0; k < numAnimals; k++) {
        if (k < numAnimals / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    for (int k = 0; k < numAnimals; k++) {
        std::cout << "Animal " << k << " (type: " << animals[k]->getType() << ") makes sound: ";
        animals[k]->makeSound();
    }
    
    for (int k = 0; k < numAnimals; k++) {
        delete animals[k];
    }
        
    std::cout << "\n\e[1;35mDog deep copy test:\033[0m" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I want to chase a ball");
    
    Dog* copyDog = new Dog(*originalDog);
    
    std::cout << "Original Dog's idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    copyDog->getBrain()->setIdea(0, "I want to chase a cat");
    std::cout << "After changing copy's idea:" << std::endl;
    std::cout << "Original Dog's idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    delete originalDog;
    delete copyDog;
    
    return 0;
}