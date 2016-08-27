#include <iostream>
#include <vector>
using namespace std;

int nwd(int a, int b) {
	int c;
	while(b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t, a;
	vector <int> number;
	cin >> t;
	while(t--) {
		cin >> a;
		number.push_back(a);
	}

	for(int i = 0; i < number.size(); i++) {
		for(int j = 0; j < number.size(); j++) {
			cout << nwd(number[i], number[j]) << " ";
		}
		cout << endl;
	}
}