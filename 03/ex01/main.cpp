#include "ScavTrap.hpp"

int main() {
    std::cout << "Testing ClapTrap" << std::endl;
    ClapTrap clap("CT-01");
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    std::cout << "\nTesting ScavTrap Construction" << std::endl;
    ScavTrap scav("ST-01");
    
    std::cout << "\nTesting ScavTrap Methods" << std::endl;
    scav.attack("Giant Enemy");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();
    
    std::cout << "\nTesting ScavTrap Copying" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("Copy Target");
    
    std::cout << "\nTesting Mixed Inheritance" << std::endl;
    ClapTrap *polyClap = &scav;
    polyClap->attack("Poly Target");
    
    std::cout << "\nEnd of tests, destructors will be called" << std::endl;
    return 0;
}