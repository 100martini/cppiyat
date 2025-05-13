#include "ClapTrap.hpp"

int main() {
    ClapTrap defaultTrap;
    ClapTrap namedTrap("Clappy");
    
    std::cout << "\nTesting attack and damage with " << namedTrap.getName() << ":" << std::endl;
    namedTrap.attack("Enemy");
    namedTrap.takeDamage(5);
    namedTrap.beRepaired(3);
    
    std::cout << "\nTesting energy depletion:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        namedTrap.attack("Enemy");
    }
    namedTrap.beRepaired(5);
    
    std::cout << "\nTesting destruction:" << std::endl;
    ClapTrap fragile("Fragile");
    fragile.takeDamage(15);
    fragile.attack("Enemy");
    fragile.beRepaired(5);
    
    std::cout << "\nTesting copy constructor:" << std::endl;
    ClapTrap original("Original");
    original.takeDamage(3);
    ClapTrap copy(original);
    std::cout << "Copy name: " << copy.getName() << ", hit points: " << copy.getHitPoints() << std::endl;
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    ClapTrap assignee;
    assignee = original;
    std::cout << "Assignee name: " << assignee.getName() << ", hit points: " << assignee.getHitPoints() << std::endl;
    
    std::cout << "\nEnd of tests, destructors will be called:" << std::endl;
    return 0;
}