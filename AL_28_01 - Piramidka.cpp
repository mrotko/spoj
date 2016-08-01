#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int length, a, b;

	cin >> length >> word;
	a = b = length / 2;

	while(a >= 0) {

		for(int i = 0; i < length; i++) {
			if(i >= a && i <= b)
				cout << word[i];
			else
				cout << ".";
		}
		cout << endl;
		a--; b++;
	}
}