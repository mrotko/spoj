#include <iostream>
#include <cmath>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;

struct Punkt {
    double x, y;
};

int main() {
    int n;
    double k;
    double pole;
    Punkt a, b, c, d;
    double A, B, C;
    cin >> n >> k;

    if(n == 3) {
        for(int i = 0; i < n; i++) {
            cin >> a.x >> a.y;
            cin >> b.x >> b.y;
            cin >> c.x >> c.y;
        }
        A = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
        B = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
        C = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));

        double obw = A + B + C;
        obw /= 2;
        pole = sqrt(obw * (obw - A) * (obw - B) * (obw - C));
        pole += A * k;
        pole += B * k;
        pole += C * k;
        pole += M_PI * k * k;
    }
    else {
        for(int i = 0; i < n; i++) {
            cin >> a.x >> a.y;
            cin >> b.x >> b.y;
            cin >> c.x >> c.y;
            cin >> d.x >> d.y;
        }
        A = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
        B = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
        pole = A * B;
        pole += 2 * A * k;
        pole += 2 * B * k;
        pole += M_PI * k * k;
    }
    cout << setprecision(6) << fixed << pole << endl;
}