#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t, n;

    cin >> t;
    while(t--) {
        cin >> n;

        if(n == 1) cout << 8 << endl;
        else if(n == 2) cout << 33 << endl;
        else {
            int sum = 0, x = n / 2;
            sum += 4 * n * n + 3 * n + 1;
            if(n % 2 == 0) sum += 2 * n * n + n;
            else sum += 2 * ((x + 1) * (2 * n + 1) - n);

            sum += 4 * (n - x) * x;
            cout << sum << endl;
        }
    }
}