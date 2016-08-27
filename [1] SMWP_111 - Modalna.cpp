#include <iostream>
#include <map>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	map <string, int> zliczLiczby;
	string liczba, modalna;
	int maxWystapien = -1;

	int n;
	cin >> n;
	while(n--) {
		cin >> liczba;
		zliczLiczby[liczba]++;
	}
	map <string, int>::iterator start = zliczLiczby.begin();

	for(int i = 0; i < zliczLiczby.size(); i++, start++)
	{
		if(start->second > maxWystapien) {
			maxWystapien = start->second;
			modalna = start->first;
		}
		else if(start->second == maxWystapien)
			modalna = "BRAK";
	}
	cout << modalna << endl;
}