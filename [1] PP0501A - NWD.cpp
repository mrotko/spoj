#include <iostream>
using namespace std;

int nwd(int a, int b);
int main()
{
    int test, a, b, i = 0;
    cin>>test;
    while(i < test)
    {
        cin>>a>>b;
        cout<<nwd(a, b)<<endl;
        i++;
    }
}
int nwd(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}