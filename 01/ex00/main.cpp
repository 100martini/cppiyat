#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("wel-kass");
    
    heapZombie->announce();
    randomChump("wel-kass");

    delete heapZombie;
    return 0;
}