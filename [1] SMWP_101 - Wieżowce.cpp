#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

struct Budynek {
    double wysokosc = 0;
    double odleglosc;
    double x, y;
};


int main() {
    ios_base::sync_with_stdio(0);
    map <pair <double, double>, Budynek> uklad;
    pair <double, double> schowek;
    double x, y, xc, yc, rc, r;
    Budynek najlepszy = {-1, -1, 0, 0};
    int n;

    cin >> xc >> yc >> rc;
    cin >> n;
    while(n--) {
        cin >> x >> y;
        r = sqrt(pow(x - xc, 2) + pow(y - yc, 2));
        if(r <= rc) {
            schowek = make_pair(x, y);
            uklad[schowek].wysokosc++;
            if(uklad[schowek].wysokosc == 1) {
                uklad[schowek].odleglosc = r;
                uklad[schowek].x = x;
                uklad[schowek].y = y;
            }
        }
    }
    map <pair <double, double>, Budynek>::iterator it = uklad.begin();

    for(int i = 0; i < uklad.size(); i++, it++) {
        if(it->second.wysokosc > najlepszy.wysokosc)
            najlepszy = it->second;
        else if(it->second.wysokosc == najlepszy.wysokosc && it->second.odleglosc < najlepszy.odleglosc)
            najlepszy = it->second;
    }
    cout << setprecision(0) << fixed << najlepszy.x << " " << najlepszy.y << " " << najlepszy.wysokosc;
}