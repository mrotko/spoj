#include <iostream>
using namespace std;

string NameDayOfWeek(int a) {
	if(a == 0) return "Pn";
	if(a == 1) return "Wt";
	if(a == 2) return "Sr";
	if(a == 3) return "Cz";
	if(a == 4) return "Pt";
	if(a == 5) return "So";
	if(a == 6) return "Nd";
}

int NumberDayOfWeek(string a) {
	if(a == "Pn") return 0;
	if(a == "Wt") return 1;
	if(a == "Sr") return 2;
	if(a == "Cz") return 3;
	if(a == "Pt") return 4;
	if(a == "So") return 5;
	if(a == "Nd") return 6;
}

int main() {
	int t, n;
	string day;

	cin >> t;

	while(t--) {
		cin >> day >> n;
		cout << NameDayOfWeek((NumberDayOfWeek(day) + n) % 7) << endl;
	}
}