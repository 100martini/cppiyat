#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Batal");
    clap.attack("Chfar");
    
    std::cout << "\nScavTrap:" << std::endl;
    ScavTrap scav("Chfar with 14");
    scav.attack("Batal");
    scav.guardGate();
    
    std::cout << "\nFragTrap:" << std::endl;
    FragTrap frag("Chfara");
    frag.attack("Bolissi");
    frag.takeDamage(30);
    frag.beRepaired(15);
    frag.highFivesGuys();
    return 0;
}