#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	vector <long long> kolejka;
	vector <long long> czas;
	vector <int> index;

	long long t, d, dlugosc;
	long long a, b, c;

	cin >> d;

	while(d--) {
		for(int i = 0; i < 3; i++) {
			cin >> dlugosc;
			kolejka.push_back(dlugosc);
		}

		for(int i = 0; i < 3; i++) {
			cin >> t;
			czas.push_back(t);
			kolejka[i] *= t;
			index.push_back(i);
		}

		for(int i = 0; i < 3; i++)
		for(int j = 0; j < 2; j++)
			if(kolejka[index[j]] > kolejka[index[j+1]])
					swap(index[j], index[j+1]);

		a = kolejka[index[0]] + czas[index[0]];
		b = kolejka[index[1]] - a;
		if(b < 0)
			b = 0;
		b += czas[index[1]];
		c = kolejka[index[2]] - b - a;
		if(c < 0)
			c = 0;
		c += czas[index[2]];

		cout << a + b + c << endl;
		kolejka.clear();
		index.clear();
		czas.clear();
	}	
}