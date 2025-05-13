#include "Character.hpp"
#include <iostream>

Character::Character() : name("unnamed"), floorSize(0), floorCapacity(10) {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
    this->floor = new AMateria*[floorCapacity];
    for (int i = 0; i < floorCapacity; i++) {
        this->floor[i] = NULL;
    }
}

Character::Character(std::string const & name) : name(name), floorSize(0), floorCapacity(10) {
    std::cout << "Character constructor called with name " << name << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
    this->floor = new AMateria*[floorCapacity];
    for (int i = 0; i < floorCapacity; i++) {
        this->floor[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name), floorSize(0), floorCapacity(10) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i] != NULL) {
            this->inventory[i] = other.inventory[i]->clone();
        } else {
            this->inventory[i] = NULL;
        }
    }
    this->floor = new AMateria*[floorCapacity];
    for (int i = 0; i < floorCapacity; i++) {
        this->floor[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        
        // Clean up existing inventory
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }
        
        // Copy inventory
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL) {
                this->inventory[i] = other.inventory[i]->clone();
            } else {
                this->inventory[i] = NULL;
            }
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] != NULL) {
            delete this->inventory[i];
        }
    }
    for (int i = 0; i < floorSize; i++) {
        if (this->floor[i] != NULL) {
            delete this->floor[i];
        }
    }
    delete[] this->floor;
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (m == NULL) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            std::cout << this->name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << this->name << " has no space to equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL) {
        return;
    }
    
    AMateria* tmp = this->inventory[idx];
    this->inventory[idx] = NULL;
    this->addToFloor(tmp);
    std::cout << this->name << " unequipped " << tmp->getType() << " from slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || this->inventory[idx] == NULL) {
        return;
    }
    
    this->inventory[idx]->use(target);
}

void Character::addToFloor(AMateria* m) {
    if (floorSize >= floorCapacity) {
        int newCapacity = floorCapacity * 2;
        AMateria** newFloor = new AMateria*[newCapacity];
        
        for (int i = 0; i < floorSize; i++) {
            newFloor[i] = floor[i];
        }
        for (int i = floorSize; i < newCapacity; i++) {
            newFloor[i] = NULL;
        }
        
        delete[] floor;
        floor = newFloor;
        floorCapacity = newCapacity;
    }
    
    floor[floorSize++] = m;
}