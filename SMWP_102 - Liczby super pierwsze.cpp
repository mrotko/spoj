#include <iostream>
using namespace std;

const int SIZE = 1000100;

int sitoErastotenesa[SIZE];

int main() {
	ios_base::sync_with_stdio(0);
	sitoErastotenesa[0] = true;
	sitoErastotenesa[1] = true;
	for(int i = 2; i * i < SIZE; i++)
		if(sitoErastotenesa[i] == false)
			for(int j = 2 * i; j < SIZE; j += i)
				sitoErastotenesa[j] = true;
	
	int n, liczba;
	bool czyPierwsza;

	cin >> n;
	while(n--) {
		cin >> liczba;
		czyPierwsza = true;
	
		while(liczba) {
			if(sitoErastotenesa[liczba] != false) {
				czyPierwsza = false;
				break;
			}
			liczba /= 10;
		}

		if(czyPierwsza)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}