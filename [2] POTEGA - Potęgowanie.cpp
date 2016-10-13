#include <iostream>

using namespace std;

string dodawanie(string a, string b) {
    int max_rozmiar = (int) max(a.length(), b.length());
    int nadwyzka = 0;

    a = string(max_rozmiar - a.length(), '0') + a;
    b = string(max_rozmiar - a.length(), '0') + b;
    string wynik = string(max_rozmiar + 1, '0');

    for(int i = max_rozmiar - 1; i >= 0; i--) {
        int w = (a[i] - '0') + (b[i] - '0') + nadwyzka;
        nadwyzka = w / 10;
        w %= 10;
        wynik[i + 1] += w;
    }
    wynik[0] += nadwyzka;
    while(wynik[0] == '0' && wynik.length() > 1) wynik.erase(0, 1);
    return wynik;
}

string mnozenie(string a, string b) {
    string wynik = "0";

    if(a.length() < b.length())
        swap(a, b);

    string wynik_czesciowy;

    int nadwyzka = 0, wiersz = 0;
    int max_rozmiar = (int) (a.length() + b.length());
    for(int i = (int) (b.length() - 1); i >= 0; i--, wiersz++) {
        wynik_czesciowy = string(max_rozmiar + 1, '0');
        for(int j = (int) (a.length() - 1), x = 0; j >= 0; j--, x++) {
            int w = (a[j] - '0') * (b[i] - '0') + nadwyzka;
            nadwyzka = w / 10;
            w %= 10;
            wynik_czesciowy[max_rozmiar - wiersz - x] += w;
        }
        wynik_czesciowy[b.length() - wiersz] += nadwyzka;
        wynik = dodawanie(wynik, wynik_czesciowy);
        nadwyzka = 0;
    }

    while(wynik[0] == '0' && wynik.length() > 1) wynik.erase(0, 1);
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    string wynik_dla_czesciowych_poteg[11];
    int potegi_2[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int max_potega;
    string wynik = "1", a;
    cin >> a >> n;

    wynik_dla_czesciowych_poteg[0] = a;

    if(a == "0") cout << 0 << endl;
    else if(n == 0 || a == "1") cout << 1 << endl;
    else {
        max_potega = 0;

        for(int i = 1; i * 2 <= n; i *= 2)
            max_potega++;

        for(int i = 1; i <= max_potega; i++)
            wynik_dla_czesciowych_poteg[i] = mnozenie(wynik_dla_czesciowych_poteg[i - 1],
                                                      wynik_dla_czesciowych_poteg[i - 1]);

        for(int i = max_potega; i >= 0; i--) {
            if(n - potegi_2[i] >= 0) {
                wynik = mnozenie(wynik, wynik_dla_czesciowych_poteg[i]);
                n -= potegi_2[i];
            }
        }
        cout << wynik << endl;
    }
}