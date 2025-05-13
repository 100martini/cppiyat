#include "DiamondTrap.hpp"

int main() {
    std::cout << "Testing DiamondTrap Construction" << std::endl;
    DiamondTrap diamond("DT-01");
    
    std::cout << "\nTesting DiamondTrap Methods" << std::endl;
    diamond.attack("Diamond Enemy");
    diamond.takeDamage(30);
    diamond.beRepaired(15);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    
    std::cout << "\nTesting Inheritance Chain" << std::endl;
    ClapTrap *polyClap = &diamond;
    polyClap->attack("Poly Target");
    
    ScavTrap *polyScav = &diamond;
    polyScav->guardGate();
    
    FragTrap *polyFrag = &diamond;
    polyFrag->highFivesGuys();
    
    std::cout << "\nTesting Copy Constructor" << std::endl;
    DiamondTrap diamondCopy(diamond);
    diamondCopy.whoAmI();
    
    std::cout << "\nEnd of tests, destructors will be called" << std::endl;
    return 0;
}