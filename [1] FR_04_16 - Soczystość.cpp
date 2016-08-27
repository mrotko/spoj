#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int d, n;
    int soczystosc[3];
    int jablko;
    cin >> d;
    while(d--) {
        cin >> n;
        soczystosc[0] = -1;
        soczystosc[1] = -1;
        soczystosc[2] = -1;
        for(int i = 0, index = 0; i < n; i++) {
            if(soczystosc[index] < 0) {
                cin >> soczystosc[index];
                index = (index + 1) % 3;
                if(soczystosc[2] > 0)
                    soczystosc[2] += soczystosc[0];
            } else {
                cin >> jablko;
                jablko += max(soczystosc[0], soczystosc[1]);
                soczystosc[0] = soczystosc[1];
                soczystosc[1] = soczystosc[2];
                soczystosc[2] = jablko;
            }
        }

        cout << max(soczystosc[0], max(soczystosc[1], soczystosc[2])) << endl;
    }
}