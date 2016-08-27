#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, x, n;

    cin >> t;
    while(t--)
    {
        cin >> x;
        n = sqrt(2*x);
        for(;n*n < 2*x+n; n++);

        if(n*n == 2*x+n) cout << "TAK\n";
        else cout << "NIE\n";
    }
}
