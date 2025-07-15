#include <iostream>
#include <vector>
#include <algorithm>

struct paket {
    int prostornina;
    int placilo;
    float placiloNaEnoto;
    unsigned long ogMesto;
};

bool primerjaj(const paket& a, const paket& b) {
    return a.placiloNaEnoto > b.placiloNaEnoto;
}

int main() {
    int stPaketov = 0;
    std::cin >> stPaketov;

    std::vector<paket> paketi;
    paketi.reserve(stPaketov);

    for (int i = 0; i < stPaketov; i++) {
        int prostornina, placilo;
        std::cin >> prostornina >> placilo;
        paket p = {prostornina, placilo, (float)placilo/(float)prostornina, paketi.size()};
        paketi.push_back(p);
    }

    std::sort(paketi.begin(), paketi.end(), primerjaj);

    int preostalProstor = 100;
    for (paket p : paketi) {
        preostalProstor -= p.prostornina;
        if (preostalProstor < 0) 
            break;
        std::cout << p.ogMesto << ' ';
    }
    return 0;
}