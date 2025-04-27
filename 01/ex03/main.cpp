#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("fight club");
        HumanA martini("wel-kass", club);
        martini.attack();
        club.setType("support-group cancer club");
        martini.attack();
    }
    {
        Weapon club = Weapon("fight club");
        HumanB nyx("ayhakimi");
        nyx.setWeapon(club);
        nyx.attack();
        club.setType("support-group cancer club");
        nyx.attack();
    }
    return 0;
}