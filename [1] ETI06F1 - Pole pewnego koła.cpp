#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double d, r;
    cin >> r >> d;
    cout << setprecision(2) << fixed << (r*r-(d*d/4))*M_PI;
}