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

    // preveri ce je beseda palindrom brez odstranjenih crk
    if (beseda == besedaNazaj(beseda)) {
        std::cout << odstranjeneCrke << '\n';
        return 0;
    }

    // odstranjuje crke dokler beseda ni palindrom
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