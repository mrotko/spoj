#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

string invert(string tekst) //  obraca liczbe
{
    string wynik;
    for(int i = 0; i < tekst.length(); i++)
        wynik.insert(0, tekst.substr(i, 1));
    return wynik;
}
string convert_to_string(int liczba)    //  zamienia liczbe calkowita na string
{
    string wynik;
    ostringstream ss;
    ss << liczba;
    wynik = ss.str();
    ss.clear();
    ss.str(string());
    return wynik;
}
bool test_palindromu(string a)  //  sprawdza czy podana liczba jest palindromem
{
    for(int i = 0; i < a.length() / 2 + 1; i++)
        if(a.at(i) != a.at(a.length() - 1 - i)) return false;
    return true;
}

int main()
{
    int t, n, ile = 0;
    string tmp;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        while(test_palindromu(convert_to_string(n)) == 0)
        {
            ile++;
            tmp = invert(convert_to_string(n));
            n += atoi(tmp.c_str());
        }
        cout << n << " " << ile << endl;
        ile = 0;
    }
}