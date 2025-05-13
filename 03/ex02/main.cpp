#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Testing ClapTrap" << std::endl;
    ClapTrap clap("CT-02");
    clap.attack("Enemy");
    
    std::cout << "\nTesting ScavTrap" << std::endl;
    ScavTrap scav("ST-02");
    scav.attack("Giant Enemy");
    scav.guardGate();
    
    std::cout << "\nTesting FragTrap Construction" << std::endl;
    FragTrap frag("FT-01");
    
    std::cout << "\nTesting FragTrap Methods" << std::endl;
    frag.attack("Massive Enemy");
    frag.takeDamage(30);
    frag.beRepaired(15);
    frag.highFivesGuys();
    
    std::cout << "\nTesting Inheritance Chain" << std::endl;
    ClapTrap *polyClap = &frag;
    polyClap->attack("Poly Target");
    
    std::cout << "\nEnd of tests, destructors will be called" << std::endl;
    return 0;
}