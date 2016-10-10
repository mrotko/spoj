#include <iostream>
using namespace std;

char plansza[10][10];

void sprawdz_droge(int x, int y) {
    int gora = -1, dol = 1, lewo = -1, prawo = 1;
    if(x < 0 || x > 9) return;
    if(y < 0 || y > 9) return;
    if(plansza[x][y] == 'X' || plansza[x][y] == 's') return;

    plansza[x][y] = 's';

    sprawdz_droge(x + lewo, y);
    sprawdz_droge(x + prawo, y);
    sprawdz_droge(x, y + gora);
    sprawdz_droge(x, y + dol);
}

int main() {
    string linia;
    ios_base::sync_with_stdio(0);
    while (getline(cin, linia)) {
        for(int i = 0, x = 0; i < 10; i++)
            for (int j = 0; j < 10; j++, x++)
                plansza[i][j] = linia.at(x);

        sprawdz_droge(0, 0);

        cout << (plansza[9][9] == 's') << endl;
    }
}