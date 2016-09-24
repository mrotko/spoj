#include <iostream>
using namespace std;

int tab[1500][1500];

int main() {
    ios_base::sync_with_stdio(0);
    int n, i, j, k, startJ = 0;

    cin >> n;

    for(i = 1; i <= n;) {
        j = startJ; k = 0;
        while(j >= 0 && i <= n) {
            tab[j][k] = i;
            j--; k++; i++;
        }
        startJ++; k = 0;
    }
    i = startJ - 1;
    startJ = 0;
    for(; i >= 0; i--) {
        startJ++;
        for(j = 0;j < startJ; j++) {
            if(tab[i][j] != 0) cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}