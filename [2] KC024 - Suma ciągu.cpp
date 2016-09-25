#include <iostream>
#include <vector>
using namespace std;

bool suma(vector <int> ciag, int s) {
    if(s == 0)
        return true;
    if(ciag.size() == 0 || s < 0)
        return false;

    int tmp = ciag[0];

    ciag.erase(ciag.begin());

    return suma(ciag, s - tmp) || suma(ciag, s);
}

int main() {
    ios_base::sync_with_stdio(0);
    int a, b, c;
    vector <int> ciag;

    while(cin >> a >> b) {
        for(int i = 0; i < b; i++) {
            cin >> c;
            ciag.push_back(c);
        }

        cout << suma(ciag, a) << endl;
        ciag.clear();
    }
}