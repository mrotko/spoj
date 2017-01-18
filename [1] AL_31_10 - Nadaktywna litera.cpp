#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void czyszczenie(int *tab, const int n)
{
	for(unsigned i = 0; i < n; i++)
		tab[i] = 0;
}

bool analiza(const string zdanie, int *tab)
{
	for(unsigned i = 0; i < zdanie.size(); i++)
	{
		if(islower(zdanie.at(i)))
		{
			int p = zdanie.at(i) - 'a';
			tab[p]++;
		}
		else if(isupper(zdanie.at(i)))
		{
			int p = zdanie.at(i) - 'A';
			tab[p]++;
		}
	}
}

string wypisz(const int *tab, const int n)
{
	string tekst = "BRAK";
	int max_1 = -1, max_2 = -1;
	int p = 0;

	for(unsigned i = 0; i < n; i++)
	{
		if(tab[i] > max_1)
		{
			max_2 = max_1;
			max_1 = tab[i];
			p = i;
		}
		else if(tab[i] > max_2)
		{
			max_2 = tab[i];
		}
	}

	if(max_1 > 2*max_2 && max_1 > 0)
		tekst = 'a' + p;

	return tekst;
}

int main()
{
	ios_base::sync_with_stdio(0);
	const int n = 30;
	int litery[n];
	int i = 1;
	string zdanie;

	while(getline(cin, zdanie, '.'))
	{
		if(zdanie == "\n") break;
		czyszczenie(litery, n);
		analiza(zdanie, litery);
		cout << i++ << " - " << wypisz(litery, n) << endl;		
	}
}