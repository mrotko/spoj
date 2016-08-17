#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    vector <int> liczba1, liczba2, wynik;
    map <char, int> konwersja;
    map <int, char> odwrocKonwersje;

    for(int i = 0; i < 10; i++) {
        konwersja['0'+ i ] = i;
        odwrocKonwersje[i] = (char)('0' + i);
    }
    for(int i = 0; i < 6; i++) {
        konwersja['A' + i] = i + 10;
        odwrocKonwersje[i + 10] = (char)('A' + i);
    }


    int p, t;
    string l1, l2;

    cin >> t;

    while(t--) {
        cin >> p >> l1 >> l2;
        wynik.push_back(0);
        for(unsigned i = 0; i < l1.length(); i++) {
            liczba1.push_back(konwersja[l1.at(i)]);
            liczba2.push_back(konwersja[l2.at(i)]);
            wynik.push_back(0);
        }

        for(int i = liczba1.size()-1; i >= 0; i--) {
            wynik[i+1] += liczba1[i] + liczba2[i];
            if(wynik[i+1] >= p) wynik[i] += 1;
            wynik[i+1] %= p;
        }

        if(wynik[0] > 0)
            cout << odwrocKonwersje[wynik[0]];
        for(int i = 1; i < wynik.size(); i++)
            cout << odwrocKonwersje[wynik[i]];
        cout << endl;

        wynik.clear();
        liczba1.clear();
        liczba2.clear();
    }
}