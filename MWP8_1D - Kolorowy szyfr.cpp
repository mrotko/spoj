#include <iostream>
#include <cmath>
using namespace std;

int toDec(char *s) {
	int dec = 0;
	char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	for(int i = 0, n = 1; i < 2; i++) {
		int x = 0;
		while(numbers[x] != s[i]) x++;
		dec += pow(16, n)*x;
		n--;
	}
	return dec;
}

int main() {
	char c, hex[2];

	while(cin >> c && c != '\n') {
		int sum = 0;
		for(int i = 0; i < 3; i++) {
			hex[0] = cin.get();
			hex[1] = cin.get();
			sum += toDec(hex);
		}
		cout << (char)sum;
	}
}