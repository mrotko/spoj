#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	vector <int> num;
	int sum, t;
	char c;
	cin >> t;
	c = cin.get();
	while(t--) {
		sum = 0;
		while(c = cin.get()) {
			if(c == '\n')
				break;
			num.push_back(c-'0');
			sum += num.back();
		}
		while(sum % 3 != 0 || num.back() % 5 != 0) {
			num[num.size()-1]--;
			sum--;
			int i = num.size()-1;
			while(i > 0 && num[i] < 0) {
				num[i] = 9;
				i--;
				num[i]--;
			}
			if(num[0] == 0 && num.size() > 1) {
				num[0] = 9;
				num.pop_back();

			}
		}
		for(int i = 0; i < num.size(); i++) 
			cout << num[i];
		cout << endl;
		num.clear();
	}
}