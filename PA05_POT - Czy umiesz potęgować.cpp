#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        b %= 4;
        if(b == 0) b = 4;
        cout << (int)pow(a % 10, b) % 10 << endl;
    }
}