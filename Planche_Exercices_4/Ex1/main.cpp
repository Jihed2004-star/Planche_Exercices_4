#include <iostream>

using namespace std;


template <class t>
void echanger(t& a, t& b) {
    t temp = a;
    a = b;
    b = temp;
}
template <class t>
void trier(t tab[],int a){
    for(int i=0;i<a-1;i++){
        int pmin=i;
        for(int j=i+1;j<a;j++){
            if(tab[i]>tab[j]){
                pmin=j;
            }
        }
        if (pmin != i) {
            echanger(tab[i], tab[pmin]);
        }
    }

}

int main()
{
    int tab[10]={29,10,14,37,13,5,19,1,7,3};
    for(int i=0; i < 10; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
    trier(tab, 10);
    for (int i=0; i < 10; i++) {
        cout << tab[i] << " ";
    }
    return 0;
}
