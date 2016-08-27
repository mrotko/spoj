#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int numberOfTest, sequenceLength, element, max = -1;
	const int SIZE = 1001;
	int drawer[SIZE];
	
	for(int i = 0; i < SIZE; i++)
		drawer[i] = 0;
	
	cin >> numberOfTest;
	while(numberOfTest--) {
		cin >> sequenceLength;
		while(sequenceLength--) {
			cin >> element;
			if(element > max) max = element;
			while(element--)
				drawer[element]++;
		}
		
		for(int i = 0; i < max; i++) {
			cout << drawer[i] << " ";
			drawer[i] = 0;
		}
			
		cout << endl;
		max = -1;
	}
}