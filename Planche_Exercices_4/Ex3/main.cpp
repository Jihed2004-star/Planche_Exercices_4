#include <iostream>
#include <vector>
using namespace std;

template <typename Func>
void appliquerFiltre(vector<int>& vec, Func filtre, int seuil = 0) {
    for (int& e : vec) {
        filtre(e, seuil);
    }
}

int main() {
    vector<int> tab{ -2, 3, -33, 7, 99, 6, 2, -39 };
    cout << "************************\n";
    cout << "* 1. Afficher positif *\n";
    cout << "* 2. Afficher Negatif *\n";
    cout << "* 3. Superieur A *\n";
    cout << "************************\n";
    cout << "Entrez votre choix?\n";
    int choix;
    cin >> choix;

    switch (choix) {
        case 1: {
            auto afficherP = [](int& x, int) {
                if (x >= 0) cout << x << "\t";
            };
            appliquerFiltre(tab, afficherP);
            break;
        }
        case 2: {
            auto afficherN = [](int& x, int) {
                if (x < 0) cout << x << "\t";
            };
            appliquerFiltre(tab, afficherN);
            break;
        }
        case 3: {
            int seuil;
            cout << "Donner seuil: ";
            cin >> seuil;
            auto greaterThan = [](int& x, int seuil) {
                if (x >= seuil) cout << x << "\t";
            };
            appliquerFiltre(tab, greaterThan, seuil);
            break;
        }
        default:
            cout << "Choix invalide.\n";
            break;
    }

    return 0;
}
