#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, tab[100];
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> tab[j];
        for(int j = 1; j < n; j++)
            cout << tab[j] << " ";
        cout << tab[0] <<endl;
    }
}

