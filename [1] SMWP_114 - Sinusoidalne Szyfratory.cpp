#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string szyfr[10];
	string tekst;
	int t, k;

	cin >> t;

	while(t--) {
		cin >> tekst >> k;

		int nast = 2*k-2, p1 = 0, p2 = 0;

		if(k == 1)
			cout << tekst;

		else {
			for(int i = 0; i < k; i++) {
				p1 = i; p2 = -i + nast;
				while(p1 < tekst.length() || p2 < tekst.length()) {
					if(p1 < tekst.length() ) cout << tekst[p1];
					if(p2 < tekst.length() && i != 0 && i != k-1) cout << tekst[p2];

					p1 += nast;
					p2 += nast;
				}
			}
		}
		cout << endl;
	}
}