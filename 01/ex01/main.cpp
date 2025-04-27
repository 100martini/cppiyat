#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Jma3a");
    
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}