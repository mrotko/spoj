#include <iostream>
using namespace std;
void sito_erastotenesa(bool *numbersTable, int n)
{
    for (int i = 2; i*i <= n; ++i )
    {
        if (numbersTable[i] == true)
            continue;
        for (int j = 2*i ; j <= n; j += i)
            numbersTable[j] = true;
    }
}
int main()
{
    bool tablica[100000] = {0};
    int a, n;
    cin >> n;
    tablica[1] = 1;
    sito_erastotenesa(tablica, 100000);
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(tablica[a] == false) cout << "TAK";
        else cout << "NIE";
        cout << endl;
    }
}
