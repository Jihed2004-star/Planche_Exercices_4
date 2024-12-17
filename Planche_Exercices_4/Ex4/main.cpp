#include <iostream>
#include <string>
using namespace std;

struct Produit {
    string type;
    double prixHT;
    bool solde;
};

double calculerPrix(const Produit& produit) {
    double taxe = (produit.type == "luxe") ? 0.25 : 0.19;
    double prixTTC = produit.prixHT * taxe+produit.prixHT;

    if (produit.solde) {
        prixTTC =prixTTC* 0.8;
    }

    return prixTTC;
}

int main() {
    Produit produit1 = {"non luxe", 100.0, false};
    Produit produit2 = {"luxe", 200.0, true};
    Produit produit3 = {"non luxe", 150.0, true};
    cout << "prix produit 1: " << calculerPrix(produit1) << " \n";
    cout << "prix produit 2: " << calculerPrix(produit2) << " \n";
    cout << "prix produit 3: " << calculerPrix(produit3) << " \n";

    return 0;
}
