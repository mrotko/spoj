#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Zawodnik
{
    string imie, nazwisko;
    double punkty = 0;

    void wypisz();
};


bool funkcjaPozycjonujaca(Zawodnik a, Zawodnik b);

int main()
{
    int t, n;
    vector <Zawodnik> konkurs;

    double punkty_za_wiatr, punkty_za_belke;
    double punkt_k;
    double belka_na_poczatku;

    string imie, nazwisko;
    double skok, wiatr, belka, nota[5];

    cin >> t;
    while(t--)
    {
        cin >> punkty_za_wiatr >> punkty_za_belke >> punkt_k >> belka_na_poczatku >> n;

        while(n--)
        {
            Zawodnik zawodnik;
            cin >> imie >> nazwisko >> skok >> wiatr >> belka;
            double min = 30, max = -1;
            
            zawodnik.imie = imie;
            zawodnik.nazwisko = nazwisko;
            
            for(unsigned i = 0; i < 5; i++)
            {
                cin >> nota[i];
                if(nota[i] > max)
                    max = nota[i];
                if(nota[i] < min)
                    min = nota[i];
                zawodnik.punkty += nota[i];
            }

            zawodnik.punkty -= (min + max);

            zawodnik.punkty += 60;
            skok -= punkt_k;

            if(punkt_k >= 60 && punkt_k <= 100)
                zawodnik.punkty += skok * 2;
            else if(punkt_k > 100 && punkt_k <= 160)
                zawodnik.punkty += skok * 1.8;
            else
                zawodnik.punkty += skok * 1.2;

            zawodnik.punkty += wiatr * punkty_za_wiatr;
            zawodnik.punkty += -1 * (belka - belka_na_poczatku) * punkty_za_belke;

            konkurs.push_back(zawodnik);
        }
        sort(konkurs.begin(), konkurs.end(), funkcjaPozycjonujaca);

        for(unsigned i = 0; i < konkurs.size(); i++)
            konkurs.at(i).wypisz();

        konkurs.clear();
    }
}

bool funkcjaPozycjonujaca(Zawodnik a, Zawodnik b)
{
    if(a.punkty != b.punkty)
        return (a.punkty > b.punkty);
    return (a.nazwisko < b.nazwisko);
}

void Zawodnik::wypisz()
{
    cout << imie << " " << nazwisko << " " << setprecision(1) << fixed << punkty << endl;
}
