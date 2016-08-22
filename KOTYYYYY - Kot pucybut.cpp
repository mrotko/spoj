#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int lewy_wiek, lewy_pozycja, prawy_wiek, prawy_pozycja;
    int t;

    cin >> t;
    while(t--) {
        cin >> lewy_wiek >> lewy_pozycja >> prawy_wiek >> prawy_pozycja;

        if(lewy_wiek > prawy_wiek) {
            if(((int) abs(prawy_pozycja - lewy_pozycja) + 1) % 3 == 2) cout << 0 << endl;
            else cout << 1 << endl;
        } else {
            if(((int) abs(prawy_pozycja - lewy_pozycja) + 1) % 3 == 2) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}