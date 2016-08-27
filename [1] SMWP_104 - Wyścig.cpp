#include <iostream>
using namespace std;

long long nwd(long long a, long long b)
{
    long long c;
    while(b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

long long nww(long long a, long long b)
{
    return (a*b)/nwd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long t, n, maxTime;

    cin >> n >> t;

    maxTime = t;
    n--;

    while(n--)
    {
        cin >> t;
        maxTime = nww(maxTime, t);
    }
    cout << maxTime << endl;
}
