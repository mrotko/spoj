#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int iloscGraczy, iloscZapytan;
	map <long long, int> krazkiGraczy;
	map <long long, int> wiecejKrazkow;
	long long krazkiJasia, x;

	cin >> iloscGraczy;
	while(iloscGraczy--) {
		cin >> x;
		krazkiGraczy[x]++;
	}

	map <long long, int>::iterator it = --krazkiGraczy.end();
	map <long long, int>::iterator prev = --krazkiGraczy.end();
	wiecejKrazkow[it->first] = 0;
	it--;
	for(int i = krazkiGraczy.size() - 1; i > 0; i--, it--, prev--) {
		long long x = wiecejKrazkow.begin()->second + prev->second;
		wiecejKrazkow[it->first] = x;
	}

	cin >> iloscZapytan;
	while(iloscZapytan--) {
		cin >> krazkiJasia;
		cout << wiecejKrazkow[krazkiJasia] << endl;
	}
}