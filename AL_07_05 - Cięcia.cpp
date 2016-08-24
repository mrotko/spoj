#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    vector <int> wysokosc, szerokosc;
    int t, x, a, b;

    cin >> a >> b >> t;

    wysokosc.push_back(0);
    wysokosc.push_back(a);
    szerokosc.push_back(0);
    szerokosc.push_back(b);

    while(t--) {
        cin >> x;
        if(x > 0) szerokosc.push_back(x);
        else wysokosc.push_back(-x);
    }

    sort(szerokosc.begin(), szerokosc.end());
    sort(wysokosc.begin(), wysokosc.end());

    long long iloscWys = 0, iloscSzer = 0, maxWys = 0, maxSzer = 0;

    for(int i = 0; i < szerokosc.size() - 1; ++i) {
        long long tmp = abs(szerokosc[i] - szerokosc[i + 1]);
        if(tmp > maxSzer) {
            maxSzer = tmp;
            iloscSzer = 1;
        } else if(tmp == maxSzer)
            iloscSzer++;
    }

    for(int i = 0; i < wysokosc.size() - 1; ++i) {
        int tmp = abs(wysokosc[i] - wysokosc[i + 1]);
        if(tmp > maxWys) {
            maxWys = tmp;
            iloscWys = 1;
        } else if(tmp == maxWys)
            iloscWys++;
    }

    cout << maxWys * maxSzer << " " << iloscSzer * iloscWys << endl;
}