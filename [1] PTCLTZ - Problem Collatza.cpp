#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        for(int j = 0; j < 10000; j++)
        {
            if(x == 1)
            {
                cout << j << endl;
                break;
            }
            if(x % 2) x = 3*x + 1;
            else x = x/2;
        }
    }
}