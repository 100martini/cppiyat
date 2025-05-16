#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Gollum");
    clap.attack("Aragorn");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    ScavTrap scav("Gollum_with_ring");
    
    std::cout << "\nScavTrap Methods:" << std::endl;
    scav.attack("Frodo");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    return 0;
}