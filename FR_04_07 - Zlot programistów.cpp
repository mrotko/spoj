#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int nwd(int a, int b) {
    int c;

    while(b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    int x, y;
    map <pair <int, int>, bool> rezerwacja;
    pair <int, int> para;
    cin >> t;
    while(t--) {
        cin >> x >> y;

        int tmp = nwd(abs(x), abs(y));
        para = make_pair(x, y);
        if(tmp != 1 || rezerwacja[para])
            cout << "NIE\n";
        else {
            cout << "TAK\n";
            rezerwacja[para] = true;
        }
    }
}