#include <iostream>
#include <climits>
using namespace std;

int listaHoteli[1003][2];

int main() {
    int dlugoscTrasy, iloscHoteli, dlugoscOdcinka = 800;

    cin >> dlugoscTrasy >> iloscHoteli;

    for(int i = 1; i <= iloscHoteli; i++)
        cin >> listaHoteli[i][0] >> listaHoteli[i][1];
    iloscHoteli++;
    listaHoteli[iloscHoteli][0] = dlugoscTrasy;
    listaHoteli[iloscHoteli][1] = 0;

    for(int i = 1; i <= iloscHoteli; i++) {
        unsigned int najtanszaTrasa = INT_MAX;
        for(int j = i-1; j >= 0 && listaHoteli[i][0] - listaHoteli[j][0] <= dlugoscOdcinka; j--) {
            if(najtanszaTrasa > listaHoteli[i][1] + listaHoteli[j][1])
                najtanszaTrasa = listaHoteli[i][1] + listaHoteli[j][1];
        }
        listaHoteli[i][1] = najtanszaTrasa;
    }

    cout << listaHoteli[iloscHoteli][1] << endl;
}