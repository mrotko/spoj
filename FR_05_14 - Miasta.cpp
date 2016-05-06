#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct City
{
	string name;
	int size, position;
};

int comp(City a, City b)
{
	if(a.size > b.size) return 1;
	if(a.size < b.size) return 2;
	if(a.name < b.name) return 1;
	if(a.name > b.name) return 2;
	return 0;
}

void sort(City *tab, int l, int r)
{
	City v = tab[(l + r)/2];

	int i = l, j = r;

	do
	{
		while(comp(v, tab[i]) == 2) i++;
		while(comp(v, tab[j]) == 1) j--;

		if(i <= j)
		{
			swap(tab[i], tab[j]);
			i++; j--;
		}

	} while(i <= j);

	if(i < r) sort(tab, i, r);
	if(j > l) sort(tab, l, j);
}

int find(City *tab, int n, int x)
{
	int l = 1, r = n-1, v;

	if(tab[0].position == x) return 0;
 	while(l < r)
	{
		v = (l + r) / 2;
		if(x > tab[v].position) l = v+1;
		else if(x < tab[v].position) r = v-1;
		else if(tab[v-1].position == tab[v].position) r = v-1;
		else if(tab[v-1].position != tab[v].position) return v;		
	}
	if(tab[l].position == x) return l;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n, q, x;

	cin >> n;

	City *real_city = new City[n];

	for(int i = 0; i < n; i++)
		cin >> real_city[i].name >> real_city[i].size;

	sort(real_city, 0, n-1);

	real_city[0].position = 1;
	for(int i = 1, p = 1; i < n; i++)
	{
		if(real_city[i].size != real_city[i-1].size) real_city[i].position = ++p;
		else real_city[i].position = p;
	}

	cin >> q;
	while(q--)
	{
		cin >> x;
		int key = find(real_city, n, x);
		if(key == -1) cout << "BRAK\n";
		else
		{
			int i = 0;
			while(key + i < n && real_city[key].position == real_city[key + i].position)
			{
				cout << real_city[key + i].name << " ";
				i++;
			}
			cout << endl;
		}
	}

	delete[] real_city;
}