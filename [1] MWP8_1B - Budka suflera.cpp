#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	vector <string> song;
	vector <string> fakeSong;
	vector <string>::iterator it;
	string tmp;
	char next;

	do {
		cin >> tmp;
		next = cin.get();
		song.push_back(tmp);
	} while(next != '\n');

	do {
		cin >> tmp;
		next = cin.get();
		fakeSong.push_back(tmp);
	} while(next != '\n');

	int size = fakeSong.size();
	for(int i = 0; i < fakeSong.size(); i++) {
		it = find(song.begin(), song.end(), fakeSong[i]);

		if(it - fakeSong.begin() != size)
			song.erase(it);
	}
	sort(song.begin(), song.end());
	cout << song.size() << endl;
	for(int i = 0; i < song.size(); i++)
		cout << song[i] << endl;	
}