#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    std::cout << "\e[1;35mtests dial subject:\033[0m" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria* tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    {
        std::cout << "\n\e[1;35mDeep copy test:\033[0m" << std::endl;
        Character* original = new Character("original");
        
        AMateria* ice = new Ice();
        AMateria* cure = new Cure();
        
        original->equip(ice);
        original->equip(cure);
        
        Character* clone = new Character(*original);
        
        std::cout << "\nOriginal before unequip:" << std::endl;
        original->use(0, *original);
        original->use(1, *original);
        
        std::cout << "\nClone after copy:" << std::endl;
        clone->use(0, *clone);
        clone->use(1, *clone);
        
        std::cout << "\nUnequipping original's materias:" << std::endl;
        original->unequip(0);
        original->unequip(1);
        
        std::cout << "\nOriginal after unequip:" << std::endl;
        original->use(0, *original);
        original->use(1, *original);
        
        std::cout << "\nClone should still have materias:" << std::endl;
        clone->use(0, *clone);
        clone->use(1, *clone);
        
        delete original;
        delete clone;
    }

    std::cout << "\n\e[1;35mMateriaSource:\033[0m" << std::endl;
    {
        MateriaSource* src = new MateriaSource();
        
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        AMateria* ice = src->createMateria("ice");
        AMateria* cure = src->createMateria("cure");
        AMateria* unknown = src->createMateria("unknown");
        
        if (ice) {
            std::cout << "Created " << ice->getType() << std::endl;
            delete ice;
        }
        
        if (cure) {
            std::cout << "Created " << cure->getType() << std::endl;
            delete cure;
        }
        
        if (unknown) {
            std::cout << "Created " << unknown->getType() << std::endl;
            delete unknown;
        } else {
            std::cout << "Unknown materia not created as expected" << std::endl;
        }
        
        delete src;
    }

    std::cout << "\n\e[1;35mCharacter inventory:\033[0m" << std::endl;
    {
        Character* hero = new Character("Hero");
        
        AMateria* materias[6];
        for (int i = 0; i < 3; i++) {
            materias[i] = new Ice();
        }
        for (int i = 3; i < 6; i++) {
            materias[i] = new Cure();
        }
        
        for (int i = 0; i < 4; i++) {
            hero->equip(materias[i]);
        }
        
        hero->equip(materias[4]);
        hero->equip(materias[5]);
        
        Character* target = new Character("Target");
        for (int i = 0; i < 4; i++) {
            hero->use(i, *target);
        }
        
        hero->use(-1, *target);
        hero->use(4, *target);
        
        hero->unequip(2);
        hero->use(2, *target); 
        
        hero->equip(materias[4]);
        hero->use(2, *target);
        
        delete materias[5];
        
        delete hero;
        delete target;
    }
    
    return 0;
}