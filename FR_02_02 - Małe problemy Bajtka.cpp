#include <iostream>

using namespace std;

int zlicz(int a) {
    int suma = 0;
    if(a == 0)
        return 1;
    while(a) {
        int tmp = a % 10;
        if(tmp == 0 || tmp == 6 || tmp == 9) suma++;
        if(tmp == 8) suma += 2;
        a /= 10;
    }
    return suma;
}

int main() {
    int max, min;
    int t, a;

    cin >> t;
    while(t--) {
        cin >> a;
        min = max = a;
        for(int i = 0; i < 5; i++) {
            cin >> a;
            if(max < a) max = a;
            if(min > a) min = a;
        }
        cout << zlicz(min) << " " << zlicz(max) << endl;
    }
}