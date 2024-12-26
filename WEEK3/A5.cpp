#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>

int main() {

    srand(time(0));

    std::array<int,10> count{0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < 30; i++) {
        int rnd = rand() % 10 + 1; 
        count[rnd-1]++;
    }

    for (int j = 0; j < 10; ++j) {
        std::cout << j+1 << " (" << count[j] << ") ";
        for (int k = 0; k < count[j]; ++k) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    return 0;
}