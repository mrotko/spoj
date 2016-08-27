#include <iostream>
using namespace std;
int main()
{
    int t, n, a, suma;
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin>>n;
        suma = 0;
        for(int j = 0; j<n; j++)
        {
            cin>>a;
            suma += a;
        }
        cout<<suma<<endl;
    }
}
