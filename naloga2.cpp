#include <iostream>
#include <string>
#include <vector>
#include <array>

std::string vrniDenar(float denar, float cena) {
    if (cena == denar)
        return "Ok";

    if (cena > denar)
        return "Manjka se " + std::to_string(cena - denar);

    float dodatniDenar = denar - cena;

    // To je dogshit, sm prakticno stackal 2 std::vectorja ku je ful pocasno
    std::vector<std::string> bankovci;

    std::array<float, 13> razpolozljiviBankovci = { 100.0f, 50.0f, 20.0f, 10.0f, 5.0f, 2.0f, 1.0f, 0.5f, 0.2f, 0.1f, 0.05f, 0.02f, 0.01f};

    // loopa cez vse bankovce, od najvecjega do najmanjsega, in doda vsakega najvecjo mozno stevilo
    for (float bankovec : razpolozljiviBankovci) {
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
    // Vcasih zmanjka nekaj denarja zaradi nepravilnosti v racunanju decimalk ( npr slavni 0.1 + 0.2 = 0.30000000000000004).
    // Da bi popravil, mislim da bi rabil fixed point library, npr https://github.com/MikeLankamp/fpm.
    // Sem tudi probal z double namesto z float ampak ni slo.
    float denar, cena;
    std::cin >> denar >> cena;
    std::cout << vrniDenar(denar, cena) << "\n";                                                                   
    return 0;
}