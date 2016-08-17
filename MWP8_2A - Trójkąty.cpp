#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Punkt {
    double x, y;
};

int main() {
    ios_base::sync_with_stdio(0);
    Punkt a1, b1, c1;
    Punkt a2, b2, c2;
    double tmp;
    bool przystajace;
    vector <double> dlugosc1;
    vector <double> dlugosc2;
    int t;

    cin >> t;
    while(t--) {
        cin >> a1.x >> a1.y >> b1.x >> b1.y >> c1.x >> c1.y;
        cin >> a2.x >> a2.y >> b2.x >> b2.y >> c2.x >> c2.y;

        tmp = sqrt(pow(a1.x - b1.x, 2) + pow(a1.y - b1.y, 2));
        dlugosc1.push_back(tmp);
        tmp = sqrt(pow(a1.x - c1.x, 2) + pow(a1.y - c1.y, 2));
        dlugosc1.push_back(tmp);
        tmp = sqrt(pow(c1.x - b1.x, 2) + pow(c1.y - b1.y, 2));
        dlugosc1.push_back(tmp);

        tmp = sqrt(pow(a2.x - b2.x, 2) + pow(a2.y - b2.y, 2));
        dlugosc2.push_back(tmp);
        tmp = sqrt(pow(a2.x - c2.x, 2) + pow(a2.y - c2.y, 2));
        dlugosc2.push_back(tmp);
        tmp = sqrt(pow(c2.x - b2.x, 2) + pow(c2.y - b2.y, 2));
        dlugosc2.push_back(tmp);

        sort(dlugosc1.begin(), dlugosc1.end());
        sort(dlugosc2.begin(), dlugosc2.end());

        przystajace = true;

        for(int i = 0; i < 3; i++)
            if(dlugosc1[i] != dlugosc2[i])
                przystajace = false;

        if(przystajace)
            cout << "TAK\n";
        else
            cout << "NIE\n";

        dlugosc1.clear();
        dlugosc2.clear();
    }
}