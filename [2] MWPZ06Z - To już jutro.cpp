#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    string c;
    int l, t, x;

    cin >> t;
    while(t--) {
        cin >> l >> c;
        if(c.length() > 2) {
            x = atoi(c.substr(c.length() - 2).c_str());
        }
        else {
            x = atoi(c.c_str());
        }

        if(x % l == 0)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}