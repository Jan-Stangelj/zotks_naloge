#include <iostream>

// Navodila so bila malo cudno napisana, zato jih jaz tako interpretiram:
// - V primeru se ne steje izgubljena kapaciteta vozlisc pirat - pirat,
//   samo pirat - OK vozlisce, jaz stejem vse.
// ce zelite rezultat kot v primeru (stejejo samo pirat - OK vozlisce) odkomentirajte #define
//#define PRIMER

#ifdef PRIMER
    #define OPERACIJA !=
#else
    #define OPERACIJA ||
#endif

unsigned int stVozlisc = 0, stPovezav = 0, stPiratskihVozlisc = 0;

struct povezava {
    unsigned int vozlisceA;
    unsigned int vozlisceB;
    unsigned int kapaciteta;
};

bool jePirat(unsigned int vozlisce) {
    return vozlisce < stPiratskihVozlisc;
}

unsigned int izgubljenaKapaciteta(povezava x) {
    if (jePirat(x.vozlisceA) OPERACIJA jePirat(x.vozlisceB))
        return x.kapaciteta;
    return 0;
}

int main() {
    std::cin >> stVozlisc >> stPovezav >> stPiratskihVozlisc;

    unsigned int izguba = 0;

    for (unsigned int i = 0; i < stPovezav; i++) {
        povezava x;
        std::cin >> x.vozlisceA >> x.vozlisceB >> x.kapaciteta;
        izguba += izgubljenaKapaciteta(x);
    }

    std::cout << izguba << '\n';

    return 0;
}