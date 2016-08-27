#include <iostream>
using namespace std;
int wynik(int a, int b);
int main()
{
    int a, b, n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>a>>b;
        cout<<wynik(a, b)<<endl;
    }
}
int wynik(int a, int b)
{
    int tmp;
    while(b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a*2;
}