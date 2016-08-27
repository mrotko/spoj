#include <iostream>
using namespace std;


void czysc(bool *tab, const int SIZE) {
    for(int i = 0; i < SIZE; i++)
        tab[i] = false;
}

void uzupelnij(bool *tab, string liczba, const int SIZE) {
    czysc(tab, SIZE);
    for (int i = 0; i < liczba.length(); i++)
        tab[liczba[i] - 'a'] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    const int SIZE = 26;
    string l1, l2, l3;
    bool palindrom;
    bool tab1[SIZE], tab2[SIZE], tab3[SIZE];
    int t;

    cin >> t;

    while(t--) {
        cin >> l1 >> l2 >> l3;
        uzupelnij(tab1, l1, SIZE);
        uzupelnij(tab2, l2, SIZE);
        uzupelnij(tab3, l3, SIZE);

        palindrom = false;
        for(int i = 0; i < SIZE; i++)
            if(tab1[i] + tab2[i] + tab3[i] > 1)
                palindrom = true;

        if(palindrom) cout << "TAK\n";
        else cout << "NIE\n";
    }
}