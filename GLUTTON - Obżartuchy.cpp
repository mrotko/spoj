#include <iostream>
using namespace std;

int main()
{
    int zestawy;
    cin>>zestawy;
    int czas, N, M, ciastka, pudelka;


    for(int i = 0; i<zestawy; i++)
    {
        ciastka = 0;
        cin>>N>>M;
        for(int j = 0; j<N; j++)
        {
            cin>>czas;
            ciastka += 86400 / czas;
        }
        if(ciastka % M == 0) pudelka = ciastka / M;
        else pudelka = (ciastka / M) + 1;
        cout<<pudelka<<endl;
    }
}