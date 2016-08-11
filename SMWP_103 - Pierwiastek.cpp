#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n > 0 && pow((int)sqrt(n), 2) == n) cout << "TAK\n";
        else cout << "NIE\n";
    }
}
