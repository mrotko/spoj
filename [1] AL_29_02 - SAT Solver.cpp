#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t, n, k, d, a;
	int zmienne[101];
	
	cin >> t;
	while(t--) {
		cin >> n >> k;
		bool sprawdzanie = true;
		bool spelnienie = true;

		for(int i = 0; i < 101; i++)
			zmienne[i] = 0;

		while(n--) {
			cin >> d;
			spelnienie = true;
			for(int i = 0; i < d; i++) {
				cin >> a;
				if(sprawdzanie) {
					if(zmienne[abs(a)] == 0)
						zmienne[abs(a)] = a;
					else
						spelnienie = spelnienie && (zmienne[abs(a)] == a);
				}
			}
			if(sprawdzanie) {
				for(int i = 0; i < 101; i++)
					zmienne[i] = 0;
			}
			if(spelnienie)
				sprawdzanie = false;
		}
		if(spelnienie)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}