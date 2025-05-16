#include "ClapTrap.hpp"

int main() {
    ClapTrap namedTrap("Ali Zaoua");
    
    std::cout << "\nWhat happened to " << namedTrap.getName() << "?" << std::endl;
    namedTrap.attack("Dib");
    namedTrap.takeDamage(5);
    namedTrap.beRepaired(3);
    namedTrap.takeDamage(8);
    namedTrap.attack("Dib");
    namedTrap.beRepaired(3);

    return 0;
}