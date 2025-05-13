#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.templates[i] != NULL) {
            this->templates[i] = other.templates[i]->clone();
        } else {
            this->templates[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (this->templates[i] != NULL) {
                delete this->templates[i];
                this->templates[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (other.templates[i] != NULL) {
                this->templates[i] = other.templates[i]->clone();
            } else {
                this->templates[i] = NULL;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL) {
            delete this->templates[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == NULL) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] == NULL) {
            this->templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource can't learn more materias" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type) {
            std::cout << "MateriaSource created " << type << std::endl;
            return this->templates[i]->clone();
        }
    }
    std::cout << "MateriaSource couldn't create unknown type " << type << std::endl;
    return NULL;
}