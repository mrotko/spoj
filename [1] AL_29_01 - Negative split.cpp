#include <iostream>
#include <cstdlib>
using namespace std;

int naSekundy(string t) {
	int wynik = 0;

	wynik += atoi(t.substr(0, 2).c_str()) * 3600;
	wynik += atoi(t.substr(3, 2).c_str()) * 60;
	wynik += atoi(t.substr(6, 2).c_str());

	return wynik;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	int a = 0, b = 0, c = 0, d = 0;
	string czas;

	/*
		0 - 0-5
		1 - 0-10
		2 - 0-15
		3 - 0-20
		4 - cala trasa
		5 - czas ktory zawodnik chcial osiagnac
	*/

	int biegacz[6];

	cin >> n;
	while(n--) {
		for(int i = 0; i < 6; i++) {
			cin >> czas;
			biegacz[i] = naSekundy(czas);
		}

		bool negativeSplit = true;

		if(biegacz[0] < biegacz[1] - biegacz[0])
			negativeSplit = false;
		if(biegacz[1] - biegacz[0] < biegacz[2] - biegacz[1])
			negativeSplit = false;
		if(biegacz[2] - biegacz[1] < biegacz[3] - biegacz[2])
			negativeSplit = false;
		if(biegacz[0] <= biegacz[3] - biegacz[2])
			negativeSplit = false;

		if(negativeSplit) {
			b++;
			if(biegacz[4] <= biegacz[5])
				a++;			
		}
		else {
			d++;
			if(biegacz[4] <= biegacz[5])
				c++;
		}
	}
	cout << a << "/" << b << " " << c << "/" << d << endl;
}