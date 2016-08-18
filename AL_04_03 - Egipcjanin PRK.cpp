#include <iostream>
using namespace std;

struct Drzewo {
    int szerokosc = 0;
    int poprzedni = -1;
    int szerokoscWyzszegoPoziomu = 0;
    int iloscElementowNaPoziomie = 0;
};

int main() {
    ios_base::sync_with_stdio(0);
    int t, n, a, b;

    Drzewo piramida[1500];
    piramida[0].szerokosc = 1;
    cin >> t;

    while(t--) {
        cin >> n;
        n--;
        while(n--) {
            cin >> a >> b;

            if(piramida[max(a, b)].szerokosc == 0) piramida[max(a, b)].szerokosc = 1;
            piramida[max(a, b)].poprzedni = min(a,b);

            int y = max(a, b);
            int x = piramida[y].poprzedni;
            int poprzedniaSzerokosc = 0;

            piramida[x].iloscElementowNaPoziomie += 1;

            while(x >= 0) {
                piramida[x].szerokoscWyzszegoPoziomu += piramida[y].szerokosc - poprzedniaSzerokosc;
                poprzedniaSzerokosc =  piramida[x].szerokosc;
                piramida[x].szerokosc = piramida[x].iloscElementowNaPoziomie + 1 + piramida[x].szerokoscWyzszegoPoziomu;

                y = x;
                x = piramida[x].poprzedni;
            }
        }

        int objetosc = 0;
        Drzewo zerowanie = {0, -1, 0, 0};
        for(int i = 0; piramida[i].szerokosc != 0; i++) {
            objetosc += piramida[i].szerokosc;
            piramida[i] = zerowanie;
        }
        cout << objetosc << endl;
    }
}