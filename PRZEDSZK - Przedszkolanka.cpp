#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, a, b, c, d, tmp;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>c>>d;
        a = c;
        b = d;
        while(b)
        {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        cout<<(c*d)/a<<endl;
    }
}
