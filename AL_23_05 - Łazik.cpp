#include <iostream>

using namespace std;

int plansza[1002][1002];

int main() {
    ios_base::sync_with_stdio(0);
    const int MOD = 1000000009;
    int d, n;
    char x;
    cin >> d;
    while(d--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> x;
                if(x == '.') plansza[i][j] = 1;
                else plansza[i][j] = 0;
            }
        }

        for(int i = 1; i < n; i++) {
            if(plansza[i-1][0] == 0) plansza[i][0] = 0;
            if(plansza[0][i-1] == 0) plansza[0][i] = 0;
        }

        for(int i = 1; i < n; ++i)
            for(int j = 1; j < n; ++j)
                if(plansza[i][j] > 0)
                    plansza[i][j] = (plansza[i - 1][j] + plansza[i][j - 1]) % MOD;

        cout << plansza[n - 1][n - 1] << endl;
    }
}