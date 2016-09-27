#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool wybierzDruzyne(vector <int> &zespol, bool znajomosc[][101], int *wybrani, int n) {
    int osoba = 0;
    while(osoba < n && wybrani[osoba] != 0)
        osoba++;

    for(int i = 0; i < n; i++) {
        if(znajomosc[osoba][i]) {
            zespol.push_back(i);
            if(wybrani[i] == 0) wybrani[i] = 1;
            else {
                wybrani[i] = -1;
                return false;
            }
        }
    }

    for(int i = 0; i < zespol.size(); i++) {
        for(int j = 0, p = zespol[i]; j < n; j++) {
            if(znajomosc[p][j] == 1) {
                if(wybrani[j] != 1) {
                    wybrani[j] = -1;
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    bool znajomosc[101][101];
    int wybrani[101];
    vector <int> zespol[3];
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> znajomosc[i][j];
        wybrani[i] = false;
    }

    if(wybierzDruzyne(zespol[0], znajomosc, wybrani, n) && wybierzDruzyne(zespol[1], znajomosc, wybrani, n) &&
       wybierzDruzyne(zespol[2], znajomosc, wybrani, n)) {
        if(zespol[0].size() + zespol[1].size() + zespol[2].size() == n && zespol[0].size() != 0 && zespol[1].size() != 0 &&
           zespol[2].size() != 0) {
            vector <int> wynik = {zespol[0].size(), zespol[1].size(), zespol[2].size()};
            sort(wynik.begin(), wynik.end());

            cout << "TAK " << wynik[0] << " " << wynik[1] << " " << wynik[2];
        }
        else cout << "NIE\n";
    }
    else
        cout << "NIE\n";
}