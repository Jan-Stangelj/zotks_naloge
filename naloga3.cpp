#include <iostream>
#include <string>

std::string besedaNazaj(const std::string& beseda) {
    std::string rezultat;
    for (int i = beseda.length() - 1; i != -1; i--) {
        rezultat.push_back(beseda[i]);
    }
    return rezultat;
}

int main() {
    std::string beseda;
    std::cin >> beseda;

    int odstranjeneCrke = 0;

    if (beseda == besedaNazaj(beseda)) {
        std::cout << odstranjeneCrke << '\n';
        return 0;
    }

    while (true) {
        odstranjeneCrke++;
        beseda.pop_back();
        if (beseda == besedaNazaj(beseda)) {
            std::cout << odstranjeneCrke << '\n';
            break;
        }
    }

    return 0;
}