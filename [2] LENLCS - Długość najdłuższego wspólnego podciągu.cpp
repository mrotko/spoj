#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string a, b;
    int n, m, t;

    cin >> t;
    while(t--) {

        cin >> n >> a;
        cin >> m >> b;
        int **tab = new int *[n + 1];

        for(int i = 0; i < n + 1; i++) {
            tab[i] = new int[m + 1];

            for(int j = 0; j < m + 1; j++)
                tab[i][j] = 0;
        }


        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i - 1] == b[j - 1])
                    tab[i][j] = tab[i - 1][j - 1] + 1;
                else
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }

        cout << tab[n][m] << endl;

        for(int i = 0; i < n; i++)
            delete[] tab[i];
        delete[] tab;
    }
}