#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << PURPLE "ScavTrap default constructor called" RESET << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << PURPLE "ScavTrap named constructor called for " << name << RESET << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << PURPLE "ScavTrap copy constructor called" RESET << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << PURPLE "\nScavTrap destructor called for " << getName() << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << PURPLE "ScavTrap assignation operator called" RESET << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (getEnergyPoints() > 0 && getHitPoints() > 0) {
        std::cout << "ScavTrap " << getName() << " brutally attacks " << target << ", causing " 
                  << getAttackDamage() << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ScavTrap " << getName() << " cannot attack. Not enough energy or hit points!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}