#include <iostream>
using namespace std;

int main()
{
    string a, b, c;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;
        for(int j = 0, k = 0;k < min(a.length(), b.length());k++)
        {
            c += a.at(k);
            j++;
            c += b.at(k);
            j++;
        }
        cout << c << endl;
        c.clear();
    }
}