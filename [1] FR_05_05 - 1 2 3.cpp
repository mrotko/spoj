#include <iostream>

using namespace std;

const int SIZE = 1000001;
int tab[SIZE];

int main() {
    ios_base::sync_with_stdio(0);

    const int MODULO = 101010101;
    tab[2] = 4;
    tab[3] = 6;

    for(int i = 4; i < SIZE; i++)
        tab[i] = (tab[i-2] * 2) % MODULO;

    int t, n;

    cin >> t;
    while(t--) {
        cin >> n;

        cout << tab[n] << endl;
    }
}