#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;

public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    ~DiamondTrap();
    
    DiamondTrap& operator=(const DiamondTrap& other);
    
    const void whoAmI() const;
    using ScavTrap::attack;
};

#endif