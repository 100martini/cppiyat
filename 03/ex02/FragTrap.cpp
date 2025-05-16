#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << PURPLE "FragTrap default constructor called" RESET << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << PURPLE "FragTrap named constructor called for " << name << RESET << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << PURPLE "FragTrap copy constructor called" RESET << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << PURPLE "\nFragTrap destructor called for " << getName() << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << PURPLE "FragTrap assignation operator called" RESET << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << getName() << " requests high fives from everyone! Put your hands up!" << std::endl;
}