#include <iostream>
#include <vector>

using namespace std;

string dodaj(string a, string b) {

    string wynik = string(max(a.length(), b.length()) + 1, '0');

    int i = (int) (a.length() - 1);
    int j = (int) (b.length() - 1);
    int k = (int) (wynik.length() - 1);
    int nast = 0;
    while(i >= 0 || j >= 0) {
        int x1 = i >= 0 ? a[i] - '0' : 0;
        int x2 = j >= 0 ? b[j] - '0' : 0;
        int w = x1 + x2 + nast;
        nast = 0;
        if(w >= 10) {
            w %= 10;
            nast++;
        }

        wynik[k] = (char) (w + '0');

        i--; j--; k--;
    }

    if(nast > 0)
        wynik[k] = '1';

    if(wynik.length() > 1 && wynik[0] == '0')
        return wynik.substr(1);
    return wynik;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        vector <vector <string>> liniaPascala(2);

        for(int i = 0; i < n + 2; i++) {
            liniaPascala[0].push_back(string(""));
            liniaPascala[1].push_back(string(""));
        }

        liniaPascala[0][0] = "1";

        int i = 0;

        for(int j = 1; j <= n; j++, i++) {
            for(int k = 0; k <= j; k++) {
                string a = k - 1 >= 0 ? liniaPascala[i % 2][k - 1] : "0";
                string b = k < j ? liniaPascala[i % 2][k] : "0";
                liniaPascala[(i + 1) % 2][k] = dodaj(a, b);
            }
        }

        for(int j = 0; j <= n; j++)
            cout << liniaPascala[i % 2][j] << " ";
        cout << endl;

        liniaPascala.clear();
    }
}