#include <iostream>
using namespace std;

void afficherPositif(int a) {
    if(a>0) {
        cout<<a<<" ";
    }
}

void afficherNegatif(int a) {
    if(a<0) {
        cout<<a<<" ";
    }
}

void afficherSupSeuil(int a, int seuil) {
    if(a>seuil) {
        cout<<a<<" ";
    }
}

void appliquerFiltre(int tab[], int taille, void (*filtre)(int)) {
    for(int i=0; i<taille; i++) {
        filtre(tab[i]);
    }
    cout<<endl;
}

void appliquerFiltreSeuil(int tab[], int taille, int seuil, void (*filtre)(int, int)) {
    for(int i=0; i<taille; i++) {
        filtre(tab[i], seuil);
    }
    cout<<endl;
}

int main() {
    const int taille=10;
    int tab[taille]={-5,3,-2,10,-7,8,0,1,-9,4};

    int choix;
    do {
        cout<<"1. afficher positives\n";
        cout<<"2. afficher  negatives\n";
        cout<<"3. afficher valeurs superieures a un seuil\n";
        cout<<"0. quitter\n";
        cout<<"votre choix : ";
        cin>>choix;

        switch(choix) {
            case 1:
                cout<<"valers positives : ";
                appliquerFiltre(tab, taille, afficherPositif);
                break;
            case 2:
                cout<<"valeurs negatives : ";
                appliquerFiltre(tab, taille, afficherNegatif);
                break;
            case 3: {
                int seuil;
                cout<<"entrer le seuil : ";
                cin>>seuil;
                cout<<"Valeurs superieure  "<<seuil<<" : ";
                appliquerFiltreSeuil(tab, taille, seuil, afficherSupSeuil);
                break;
            }
            case 0:
                break;
            default:
                break;
        }
    } while(choix!=0);

    return 0;
}
