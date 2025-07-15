#include <iostream>
#include <string>
#include <vector>
#include <array>

std::string vrniDenar(double denar, double cena) {
    if (cena == denar)
        return "Ok";

    if (cena > denar)
        return "Manjka se " + std::to_string(cena - denar);

    double dodatniDenar = denar - cena;

    // To je dogshit, sm prakticno stackal 2 std::vectorja ku je ful pocasno
    std::vector<std::string> bankovci;
    std::array<double, 13> razpolozljiviBankovci = { 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1f, 0.05, 0.02, 0.01};

    for (double bankovec : razpolozljiviBankovci) {
        while (true) {
            if (dodatniDenar < bankovec)
                break;

            bankovci.push_back(std::to_string(bankovec));
            dodatniDenar -= bankovec;
        }
    }

    std::string returnVal;

    returnVal.append("Vracilo:\n");

    for (std::string i : bankovci)
        returnVal.append(i + '\n');

    return returnVal;
}

int main() {
    // Vcasih zmanjka nekaj denarja zaradi nepravilnosti v racunanju decimalk ( npr slavni 0.1 + 0.2 = 0.30000000000000004)
    // Da bi popravil, mislim da bi rabil fixed point library, npr https://github.com/MikeLankamp/fpm
    std::cout << vrniDenar(10.0, 4.68) << "\n";                                                                   
    return 0;
}