#include <iostream>
#include <string>
#include <cmath>

int main(void) {
    std::string vhod;

    std::cin >> vhod;

    int vhodStevilka = std::stoi(vhod);

    int sestevek = 0;

    for (unsigned int i = 0; i < vhod.size(); i++) {
        int stevilka = vhod[i] - '0';
        sestevek += pow(stevilka, stevilka);
    }

    if (vhodStevilka == sestevek) {
        std::cout << "1\n";
        return 0;
    }

    std::cout << "0\n";
    return 0;
}