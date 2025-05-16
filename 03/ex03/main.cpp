#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("DTA");
    
    std::cout << "\nDiamondTrap:" << std::endl;
    std::cout << "\nWhat happened to " << diamond.getName() << "?" << std::endl;
    diamond.attack("DTE");
    diamond.takeDamage(30);
    diamond.beRepaired(15);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    
    return 0;
}