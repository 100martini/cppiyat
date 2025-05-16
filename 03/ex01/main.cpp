#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Gollum");

    std::cout << "\nWhat happened to " << clap.getName() << "?" << std::endl;
    clap.attack("Aragorn");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    ScavTrap scav("Gollum_with_ring");
    
    std::cout << "\nScavTrap:" << std::endl;
    std::cout << "\nWhat happened to " << scav.getName() << "?" << std::endl;
    scav.attack("Frodo");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    return 0;
}