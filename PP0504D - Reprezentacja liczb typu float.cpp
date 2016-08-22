#include <iostream>
#include <sstream>
using namespace std;

union k
{
    float l;
    struct p
    {
        int a : 8,
            b : 8,
            c : 8,
            d : 8;
    };
    p x;
};

int main()
{
    ios_base::sync_with_stdio(0);
    k liczba;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> liczba.l;
        ostringstream aa, bb, cc, dd;
        aa << hex << liczba.x.a;
        bb << hex << liczba.x.b;
        cc << hex << liczba.x.c;
        dd << hex << liczba.x.d;
        string tmp;
        tmp = dd.str();
        while(tmp[0] == 'f' && tmp.length() > 2)
            tmp.erase(0, 1);
        cout << tmp << " ";
        tmp = cc.str();
        while(tmp[0] == 'f' && tmp.length() > 2)
            tmp.erase(0, 1);
        cout << tmp << " ";
        tmp = bb.str();
        while(tmp[0] == 'f' && tmp.length() > 2)
            tmp.erase(0, 1);
        cout << tmp << " ";
        tmp = aa.str();
        while(tmp[0] == 'f' && tmp.length() > 2)
            tmp.erase(0, 1);
        cout << tmp << endl;
    }
}
