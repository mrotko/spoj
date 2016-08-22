#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    double A1, B1, A2, B2;
    int t;

    cin >> t;
    while(t--) {
        cin >> A1 >> B1 >> A2 >> B2;

        if(A1 < B1) swap(A1, B1);
        if(A2 < B2) swap(A2, B2);
        if(A1 > A2 && B1 > B2) cout << "TAK\n";
        else if(A1 <= A2 && B1 <= B2) cout << "NIE\n";
        else {
            double d1, d2;
            d1 = sqrt(A1 * A1 + B1 * B1);
            d2 = sqrt(A2 * A2 + B2 * B2);
            if(d1 <= d2) cout << "NIE\n";
            else {
                double a, b, c;
                a = 0.5 * A1 - sqrt(pow(0.5 * d2, 2) - pow(0.5 * B1, 2));
                b = 0.5 * B1 - sqrt(pow(0.5 * d2, 2) - pow(0.5 * A1, 2));
                c = sqrt(a * a + b * b);

                if(c > B2) cout << "TAK\n";
                else cout << "NIE\n";
            }
        }
    }
}