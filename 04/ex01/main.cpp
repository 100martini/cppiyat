#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "\e[1;35mtests dial subject:\033[0m" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    std::cout << "\n\e[1;35marrays:\033[0m" << std::endl;
    const int numAnimals = 10;
    Animal* animals[numAnimals];
    
    for (int k = 0; k < numAnimals; k++) {
        if (k < numAnimals / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    for (int k = 0; k < numAnimals; k++) {
        delete animals[k];
    }
        
    std::cout << "\n\e[1;35mDog deep copy test:\033[0m" << std::endl;
    Dog* originalDog = new Dog();

    originalDog->getBrain()->setIdea(0, "I want to chase a ball");
    originalDog->getBrain()->setIdea(1, "I love my human");
    
    Dog* copyDog = new Dog(*originalDog);
    
    std::cout << "Original Dog's idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    copyDog->getBrain()->setIdea(0, "I want to chase a cat");
    std::cout << "After changing copy's idea:" << std::endl;
    std::cout << "Original Dog's idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
    
    delete originalDog;
    delete copyDog;
    
    std::cout << "\n\e[1;35mCat deep copy test:\033[0m" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "I want to sleep");
    originalCat->getBrain()->setIdea(1, "I don't care about humans");
    
    Cat copyCat;
    copyCat = *originalCat;
    
    std::cout << "Original Cat's idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat's idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    copyCat.getBrain()->setIdea(0, "I want to eat fish");
    std::cout << "After changing copy's idea:" << std::endl;
    std::cout << "Original Cat's idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Cat's idea 0: " << copyCat.getBrain()->getIdea(0) << std::endl;
    
    delete originalCat;
    
    return 0;
}