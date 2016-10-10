#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int licznik[70];
    int mianownik[70];

    long double wynik;
    int t, n, k;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        wynik = 1;

        for(int i = 1; i <= n; i++) {
            licznik[i] = i;
            mianownik[i] = 1;
        }

        for(int i = 1; i <= k; i++)
            mianownik[i] *= i;

        for(int i = 1; i <= (n-k); i++)
            mianownik[i] *= i;

        for(int i = n, a, b; i >= 2; i--) {
            a = 1; b = 1;
            while(a <= n && b <= n) {
                while(a <= n && licznik[a] % i != 0)
                    a++;

                while(b <= n && mianownik[b] % i != 0)
                    b++;

                if(a <= n && b <= n) {

                    licznik[a] /= i;
                    mianownik[b] /= i;
                }
            }
        }

        for(int i = 1; i <= n; i++)
            wynik *= licznik[i];

        cout <<setprecision(0) << fixed << wynik << endl;
    }
}