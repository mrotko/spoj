#include <iostream>

using namespace std;

int main() {
    int t, n;

    cin >> t;
    while(t--) {
        cin >> n;
        int sum = 0, x;
        if(n > 36) cout << 0 << endl;
        else {
            for(int s = 0; s <= min(9, n); s++) {
                for(int d1 = 0; d1 <= min(9, n); d1++) {
                    for(int d2 = 0; d2 <= min(9, n); d2++) {
                        x = n - s - d1 - d2;
                        if(x >= 0 && x <= min(9, n))
                            for(int d3 = 0; d3 <= min(9, n); d3++) {
                                x = n - s - d2 - d3;
                                if(x >= 0 && x <= min(9, n))
                                    for(int d4 = 0; d4 <= min(9, n); d4++) {
                                        int test = 0;
                                        x = n - s - d3 - d4;
                                        if(x >= 0 && x <= min(9, n)) test++;
                                        x = n - s - d4 - d1;
                                        if(x >= 0 && x <= min(9, n)) test++;
                                        if(test == 2)
                                            sum++;
                                    };
                            };
                    };
                }
            }
            cout << sum << endl;
        }
    }
}