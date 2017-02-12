#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Rekord
{
    string linia;
    string imie;
    string nazwisko;
    string wiek;
    string pesel;

    void wytnij_imie();
    void wytnij_nazwisko();
    void wytnij_wiek();
    void wytnij_pesel();
    void wytnij();
    void wypisz();
};

bool funkcjaPozycjonujaca(Rekord a, Rekord b);

int main()
{
    ios_base::sync_with_stdio(0);
    string linia;
    Rekord rekord;
    vector <Rekord> dane;

    while(cin >> linia)
    {
        rekord.linia = linia;
        rekord.wytnij();
        dane.push_back(rekord);
    }

    sort(dane.begin(), dane.end(), funkcjaPozycjonujaca);

    for(unsigned i = 0; i < dane.size(); i++)
        dane.at(i).wypisz();
}

void Rekord::wytnij_imie()
{
    int i = linia.find('.');
    imie = linia.substr(i-1, 2);
    linia.erase(i-1, 2);
}

void Rekord::wytnij_nazwisko()  //  imie jest wcześniej wycięte
{
    unsigned x, y;
    for(unsigned i = 0; i < linia.length(); i++)
    {
        if(isalpha(linia.at(i)))
        {
            x = i;
            while(i < linia.length() && isalpha(linia.at(i)))
                i++;
            y = i;
            break;
        }
    }

    int len = y - x;
    nazwisko = linia.substr(x, len);
    linia.erase(x, len);
}

void Rekord::wytnij_wiek()  //  nazwisko jest wcześniej wycięte
{
    unsigned x;
    if(linia.at(0) < '4')
        x = 0;
    else
        x = linia.length() - 2;

    wiek = linia.substr(x, 2);
    linia.erase(x, 2);
}

void Rekord::wytnij_pesel() //  wiek jest wcześniej wycięty
{
    pesel = linia;
}

void Rekord::wytnij()
{
    wytnij_imie();
    wytnij_nazwisko();
    wytnij_wiek();
    wytnij_pesel();
}

void Rekord::wypisz()
{
    cout << imie << " " << nazwisko << " " << wiek << " " << pesel << endl;
}

bool funkcjaPozycjonujaca(Rekord a, Rekord b)
{
    if(a.nazwisko != b.nazwisko)
        return (a.nazwisko < b.nazwisko);
    if(a.imie != b.imie)
        return (a.imie < b.imie);
    return (a.pesel > b.pesel);
}
