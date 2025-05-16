#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Batal");

    std::cout << "\nWhat happened to " << clap.getName() << "?" << std::endl;
    clap.attack("Chfar");
    
    std::cout << "\nScavTrap:" << std::endl;
    ScavTrap scav("Chfar with 14");
    
    std::cout << "\nWhat happened to " << scav.getName() << "?" << std::endl;
    scav.attack("Batal");
    scav.guardGate();
    
    std::cout << "\nFragTrap:" << std::endl;
    FragTrap frag("Chfara");
    std::cout << "\nWhat happened to " << frag.getName() << "?" << std::endl;
    frag.attack("Bolissi");
    frag.takeDamage(30);
    frag.beRepaired(15);
    frag.highFivesGuys();
    return 0;
}