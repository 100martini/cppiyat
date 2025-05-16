#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("DT-00");
    
    std::cout << "\nDiamondTrap:" << std::endl;
    diamond.attack("Diamond Enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(15);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    
    return 0;
}