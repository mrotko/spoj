#include <iostream>
using namespace std;
int silnia(int n);
int main()
{
    int d, a, wynik;
    cin>>d;
    for(int i = 0; i<d; i++)
    {
        cin>>a;
        if(a > 9)
            cout<<"0 0"<<endl;
        else
        {
            wynik = silnia(a) % 100;
            cout<<wynik / 10<<" "<<wynik % 10<<endl;
        }
    }
}
int silnia(int n)
{
    if(n == 0) return 1;
    else return n*silnia(n-1);
}