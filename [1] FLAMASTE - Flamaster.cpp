#include <iostream>
using namespace std;
int main()
{
    int c, licznik = 1;
    const int ile = 201;
    char tekst[ile];
    cin>>c;
    for(int i = 0; i<c; i++)
    {
        cin>>tekst;
        for(int j = 0; j<ile - 1; j++)
        {
            if(tekst[j] == NULL) break;         //  jezeli koniec tekstu to przerywa petle
            if(licznik < 3)
            {
                if(tekst[j] == tekst[j+1]) licznik++;   //  jezeli litera sie powtarza to zwieksza sie licznik
                else licznik = 1;                       //  jezeli litera sie nie powtorzy to licznik dostaje poczatkowa wartosc
                if(licznik < 3) cout<<tekst[j];         //  jezeli wystapily maksymalnie 2 litery to wypisuje je
            }                                           //  a jezeli wystapi 3 litera taka sama z rzedu to nie wypisze 2 litery
            else
            {
                if(tekst[j] == tekst[j+1]) licznik++;   //  liczenie ile liter takich samych wystepuje z rzedu
                else
                {
                    cout<<licznik;                      //  jezeli nastepna litera jest inna to licznik dostaje poczatkowa wartosc
                    licznik = 1;
                }
            }
        }
        cout<<endl;
    }
}