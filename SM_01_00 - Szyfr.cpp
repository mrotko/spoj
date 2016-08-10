#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int i, l, d;
    char a;

    cin >> d;
    cin.get(a);
    while(d--)
    {
        i = 4; l = 0;
        while(cin.get(a))
        {
            if(a == '\n') break;
            if(i == -1)
            {
                cout << (char)(l+65);
                i = 4;
                l = 0;
            }
            l += (a - '0') * pow(2, i);
            i--;
        }
        cout << (char)(l+65) << endl;
    }
}
