#include <iostream>
using namespace std;

struct Punkt {
    int x, y;
    void pokaz() {
        cout << x << " " << y << endl;
    }
};

struct Ogranicznik {
    int polnoc, poludnie = 1, zachod = 1, wschod;
};

int main() {
    ios_base::sync_with_stdio(0);
    int x, y, t;
    string komunikat;
    Punkt p;

    cin >> t;

    while(t--) {
        cin >> x >> y;
        Ogranicznik granica;
        granica.polnoc = granica.poludnie + y;
        granica.wschod = granica.zachod + x;
        while(true) {
            p.x = (granica.zachod + granica.wschod) / 2;
            p.y = (granica.polnoc + granica.poludnie) / 2;
            p.pokaz();
            cin >> komunikat;
            if(komunikat == "OK") break;
            if(komunikat == "N") granica.poludnie = p.y;
            if(komunikat == "E") granica.zachod = p.x;
            if(komunikat == "S") granica.polnoc = p.y;
            if(komunikat == "W") granica.wschod = p.x;
            if(komunikat == "NE") {
                granica.zachod = p.x;
                granica.poludnie = p.y;
            }
            if(komunikat == "NW") {
                granica.poludnie = p.y;
                granica.wschod = p.x;
            }
            if(komunikat == "SE") {
                granica.polnoc = p.y;
                granica.zachod = p.x;
            }
            if(komunikat == "SW") {
                granica.polnoc = p.y;
                granica.wschod = p.x;
            }
        }
    }
}