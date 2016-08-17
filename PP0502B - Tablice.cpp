#include <iostream>
using namespace std;
int main()
{
    int t, n, tab[100];
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin>>n;
        for(int j = 0; j<n; j++)
            cin>>tab[j];
        for(int j = 0; j<n; j++)
            cout<<tab[n - (j+1)]<<" ";
        cout<<endl;
    }
}
